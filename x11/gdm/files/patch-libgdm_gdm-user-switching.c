--- libgdm/gdm-user-switching.c.orig	2015-07-20 13:13:45 UTC
+++ libgdm/gdm-user-switching.c
@@ -31,12 +31,25 @@
 #include <glib-object.h>
 #include <gio/gio.h>
 
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-login.h>
+#endif
 
 #include "common/gdm-common.h"
 #include "gdm-user-switching.h"
 #include "gdm-client.h"
 
+#ifdef WITH_CONSOLE_KIT
+#define CK_NAME      "org.freedesktop.ConsoleKit"
+#define CK_PATH      "/org/freedesktop/ConsoleKit"
+#define CK_INTERFACE "org.freedesktop.ConsoleKit"
+
+#define CK_MANAGER_PATH      "/org/freedesktop/ConsoleKit/Manager"
+#define CK_MANAGER_INTERFACE "org.freedesktop.ConsoleKit.Manager"
+#define CK_SEAT_INTERFACE    "org.freedesktop.ConsoleKit.Seat"
+#define CK_SESSION_INTERFACE "org.freedesktop.ConsoleKit.Session"
+#endif
+
 static gboolean
 create_transient_display (GDBusConnection *connection,
                           GCancellable    *cancellable,
@@ -67,12 +80,304 @@ create_transient_display (GDBusConnectio
         return TRUE;
 }
 
+#ifdef WITH_CONSOLE_KIT
+
 static gboolean
-activate_session_id (GDBusConnection  *connection,
-                     GCancellable     *cancellable,
-                     const char       *seat_id,
-                     const char       *session_id,
-                     GError          **error)
+get_current_session_id (GDBusConnection  *connection,
+                        char            **session_id)
+{
+        GError *local_error = NULL;
+        GVariant *reply;
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             CK_NAME,
+                                             CK_MANAGER_PATH,
+                                             CK_MANAGER_INTERFACE,
+                                             "GetCurrentSession",
+                                             NULL, /* parameters */
+                                             G_VARIANT_TYPE ("(o)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL, &local_error);
+        if (reply == NULL) {
+                g_warning ("Unable to determine session: %s", local_error->message);
+                g_error_free (local_error);
+                return FALSE;
+        }
+
+        g_variant_get (reply, "(o)", session_id);
+        g_variant_unref (reply);
+
+        return TRUE;
+}
+
+static gboolean
+get_seat_id_for_session (GDBusConnection  *connection,
+                         const char       *session_id,
+                         char            **seat_id)
+{
+        GError *local_error = NULL;
+        GVariant *reply;
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             CK_NAME,
+                                             session_id,
+                                             CK_SESSION_INTERFACE,
+                                             "GetSeatId",
+                                             NULL, /* parameters */
+                                             G_VARIANT_TYPE ("(o)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL, &local_error);
+        if (reply == NULL) {
+                g_warning ("Unable to determine seat: %s", local_error->message);
+                g_error_free (local_error);
+                return FALSE;
+        }
+
+        g_variant_get (reply, "(o)", seat_id);
+        g_variant_unref (reply);
+
+        return TRUE;
+}
+
+static char *
+get_current_seat_id (GDBusConnection *connection)
+{
+        gboolean res;
+        char    *session_id;
+        char    *seat_id;
+
+        session_id = NULL;
+        seat_id = NULL;
+
+        res = get_current_session_id (connection, &session_id);
+        if (res) {
+                res = get_seat_id_for_session (connection, session_id, &seat_id);
+        }
+        g_free (session_id);
+
+        return seat_id;
+}
+
+static gboolean
+activate_session_id_for_ck (GDBusConnection *connection,
+                            GCancellable    *cancellable,
+                            const char      *seat_id,
+                            const char      *session_id,
+                            GError         **error)
+{
+        GVariant *reply;
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             CK_NAME,
+                                             seat_id,
+                                             CK_SEAT_INTERFACE,
+                                             "ActivateSession",
+                                             g_variant_new ("(o)", session_id),
+                                             NULL,
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL, error);
+        if (reply == NULL) {
+                g_prefix_error (error, _("Unable to activate session: "));
+                return FALSE;
+        }
+
+        g_variant_unref (reply);
+
+        return TRUE;
+}
+
+static gboolean
+session_is_login_window (GDBusConnection *connection,
+                         const char      *session_id)
+{
+        GError *local_error = NULL;
+        GVariant *reply;
+        const char *value;
+        gboolean ret;
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             CK_NAME,
+                                             session_id,
+                                             CK_SESSION_INTERFACE,
+                                             "GetSessionType",
+                                             NULL,
+                                             G_VARIANT_TYPE ("(s)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL, &local_error);
+        if (reply == NULL) {
+                g_warning ("Unable to determine session type: %s", local_error->message);
+                g_error_free (local_error);
+                return FALSE;
+        }
+
+        g_variant_get (reply, "(&s)", &value);
+
+        if (value == NULL || value[0] == '\0' || strcmp (value, "LoginWindow") != 0) {
+                ret = FALSE;
+        } else {
+                ret = TRUE;
+        }
+
+        g_variant_unref (reply);
+
+        return ret;
+}
+
+static gboolean
+seat_can_activate_sessions (GDBusConnection *connection,
+                            const char      *seat_id)
+{
+        GError *local_error = NULL;
+        GVariant *reply;
+        gboolean ret;
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             CK_NAME,
+                                             seat_id,
+                                             CK_SEAT_INTERFACE,
+                                             "CanActivateSessions",
+                                             NULL,
+                                             G_VARIANT_TYPE ("(b)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL, &local_error);
+        if (reply == NULL) {
+                g_warning ("Unable to determine if can activate sessions: %s", local_error->message);
+                g_error_free (local_error);
+                return FALSE;
+        }
+
+        g_variant_get (reply, "(b)", &ret);
+        g_variant_unref (reply);
+
+        return ret;
+}
+
+static const char **
+seat_get_sessions (GDBusConnection *connection,
+                   const char      *seat_id)
+{
+        GError *local_error = NULL;
+        GVariant *reply;
+        const char **value;
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             CK_NAME,
+                                             seat_id,
+                                             CK_SEAT_INTERFACE,
+                                             "GetSessions",
+                                             NULL,
+                                             G_VARIANT_TYPE ("(ao)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL, &local_error);
+        if (reply == NULL) {
+                g_warning ("Unable to list sessions: %s", local_error->message);
+                g_error_free (local_error);
+                return FALSE;
+        }
+
+        g_variant_get (reply, "(^ao)", &value);
+        g_variant_unref (reply);
+
+        return value;
+}
+
+static gboolean
+get_login_window_session_id_for_ck (GDBusConnection  *connection,
+                                    const char       *seat_id,
+                                    char            **session_id)
+{
+        gboolean     can_activate_sessions;
+        const char **sessions;
+        int          i;
+
+        *session_id = NULL;
+        sessions = NULL;
+
+        g_debug ("checking if seat can activate sessions");
+
+        can_activate_sessions = seat_can_activate_sessions (connection, seat_id);
+        if (! can_activate_sessions) {
+                g_debug ("seat is unable to activate sessions");
+                return FALSE;
+        }
+
+        sessions = seat_get_sessions (connection, seat_id);
+        for (i = 0; sessions [i] != NULL; i++) {
+                const char *ssid;
+
+                ssid = sessions [i];
+
+                if (session_is_login_window (connection, ssid)) {
+                        *session_id = g_strdup (ssid);
+                        break;
+                }
+        }
+        g_free (sessions);
+
+        return TRUE;
+}
+
+static gboolean
+goto_login_session_for_ck (GDBusConnection  *connection,
+                           GCancellable     *cancellable,
+                           GError          **error)
+{
+        gboolean        ret;
+        gboolean        res;
+        char           *session_id;
+        char           *seat_id;
+
+        ret = FALSE;
+
+        /* First look for any existing LoginWindow sessions on the seat.
+           If none are found, create a new one. */
+
+        seat_id = get_current_seat_id (connection);
+        if (seat_id == NULL || seat_id[0] == '\0') {
+                g_debug ("seat id is not set; can't switch sessions");
+                g_set_error (error, GDM_CLIENT_ERROR, 0, _("Could not identify the current session."));
+
+                return FALSE;
+        }
+
+        res = get_login_window_session_id_for_ck (connection, seat_id, &session_id);
+        if (! res) {
+                g_set_error (error, GDM_CLIENT_ERROR, 0, _("User unable to switch sessions."));
+                return FALSE;
+        }
+
+        if (session_id != NULL) {
+                res = activate_session_id_for_ck (connection, cancellable, seat_id, session_id, error);
+                if (res) {
+                        ret = TRUE;
+                }
+        }
+
+        if (! ret && g_strcmp0 (seat_id, "/org/freedesktop/ConsoleKit/Seat1") == 0) {
+                res = create_transient_display (connection, cancellable, error);
+                if (res) {
+                        ret = TRUE;
+                }
+        }
+
+        return ret;
+}
+#endif
+
+#ifdef WITH_SYSTEMD
+
+static gboolean
+activate_session_id_for_systemd (GDBusConnection  *connection,
+                                 GCancellable     *cancellable,
+                                 const char       *seat_id,
+                                 const char       *session_id,
+                                 GError          **error)
 {
         GVariant *reply;
 
@@ -97,8 +402,8 @@ activate_session_id (GDBusConnection  *c
 }
 
 static gboolean
-get_login_window_session_id (const char  *seat_id,
-                             char       **session_id)
+get_login_window_session_id_for_systemd (const char  *seat_id,
+                                         char       **session_id)
 {
         gboolean   ret;
         int        res, i;
@@ -182,9 +487,9 @@ out:
 }
 
 static gboolean
-goto_login_session (GDBusConnection  *connection,
-                    GCancellable     *cancellable,
-                    GError          **error)
+goto_login_session_for_systemd (GDBusConnection  *connection,
+                                GCancellable     *cancellable,
+                                GError          **error)
 {
         gboolean        ret;
         int             res;
@@ -238,9 +543,9 @@ goto_login_session (GDBusConnection  *co
                 return FALSE;
         }
 
-        res = get_login_window_session_id (seat_id, &session_id);
+        res = get_login_window_session_id_for_systemd (seat_id, &session_id);
         if (res && session_id != NULL) {
-                res = activate_session_id (connection, cancellable, seat_id, session_id, error);
+                res = activate_session_id_for_systemd (connection, cancellable, seat_id, session_id, error);
 
                 if (res) {
                         ret = TRUE;
@@ -259,10 +564,11 @@ goto_login_session (GDBusConnection  *co
 
         return ret;
 }
+#endif
 
 gboolean
 gdm_goto_login_session_sync (GCancellable  *cancellable,
-                             GError       **error)
+			     GError       **error)
 {
         GDBusConnection *connection;
         gboolean retval;
@@ -271,8 +577,23 @@ gdm_goto_login_session_sync (GCancellabl
         if (!connection)
                 return FALSE;
 
-        retval = goto_login_session (connection, cancellable, error);
+#ifdef WITH_SYSTEMD
+        if (LOGIND_RUNNING()) {
+                retval = goto_login_session_for_systemd (connection,
+                                                         cancellable,
+                                                         error);
+
+                g_object_unref (connection);
+                return retval;
+        }
+#endif
+
+#ifdef WITH_CONSOLE_KIT
+        retval = goto_login_session_for_ck (connection, cancellable, error);
 
         g_object_unref (connection);
         return retval;
+#else
+        return FALSE;
+#endif
 }
