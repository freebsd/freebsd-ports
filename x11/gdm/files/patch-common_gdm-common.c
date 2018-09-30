$OpenBSD: patch-common_gdm-common_c,v 1.4 2015/10/18 13:25:54 ajacoutot Exp $

REVERT - OpenBSD does not have a systemd implementation (we need ConsoleKit)
From 9be58c9ec9a3a411492a5182ac4b0d51fdc3a323 Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Fri, 12 Jun 2015 13:48:52 -0400
Subject: require logind support

REVERT - OpenBSD does not have a systemd implementation (we need ConsoleKit)
From 1ac67f522f5690c27023d98096ca817f12f7eb88 Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Fri, 12 Jun 2015 13:28:01 -0400
Subject: drop consolekit support

--- common/gdm-common.c.orig	Sun Oct 18 14:26:27 2015
+++ common/gdm-common.c	Sun Oct 18 14:24:34 2015
@@ -39,12 +39,25 @@
 #include "mkdtemp.h"
 #endif
 
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-login.h>
+#endif
 
 #define GDM_DBUS_NAME                            "org.gnome.DisplayManager"
 #define GDM_DBUS_LOCAL_DISPLAY_FACTORY_PATH      "/org/gnome/DisplayManager/LocalDisplayFactory"
 #define GDM_DBUS_LOCAL_DISPLAY_FACTORY_INTERFACE "org.gnome.DisplayManager.LocalDisplayFactory"
 
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
 G_DEFINE_QUARK (gdm-common-error, gdm_common_error);
 
 const char *
@@ -343,15 +356,306 @@ create_transient_display (GDBusConnection *connection,
         return TRUE;
 }
 
+#ifdef WITH_CONSOLE_KIT
+
 static gboolean
-activate_session_id (GDBusConnection *connection,
-                     const char      *seat_id,
-                     const char      *session_id)
+get_current_session_id (GDBusConnection  *connection,
+                        char            **session_id)
 {
         GError *local_error = NULL;
         GVariant *reply;
 
         reply = g_dbus_connection_call_sync (connection,
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
+                            const char      *seat_id,
+                            const char      *session_id)
+{
+        GError *local_error = NULL;
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
+                                             NULL, &local_error);
+        if (reply == NULL) {
+                g_warning ("Unable to activate session: %s", local_error->message);
+                g_error_free (local_error);
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
+                g_set_error (error, GDM_COMMON_ERROR, 0, _("Could not identify the current session."));
+
+                return FALSE;
+        }
+
+        res = get_login_window_session_id_for_ck (connection, seat_id, &session_id);
+        if (! res) {
+                g_set_error (error, GDM_COMMON_ERROR, 1, _("User unable to switch sessions."));
+                return FALSE;
+        }
+
+        if (session_id != NULL) {
+                res = activate_session_id_for_ck (connection, seat_id, session_id);
+                if (res) {
+                        ret = TRUE;
+                }
+        }
+
+        if (! ret && g_strcmp0 (seat_id, "/org/freedesktop/ConsoleKit/Seat1") == 0) {
+                res = create_transient_display (connection, error);
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
+activate_session_id_for_systemd (GDBusConnection *connection,
+                                 const char      *seat_id,
+                                 const char      *session_id)
+{
+        GError *local_error = NULL;
+        GVariant *reply;
+
+        reply = g_dbus_connection_call_sync (connection,
                                              "org.freedesktop.login1",
                                              "/org/freedesktop/login1",
                                              "org.freedesktop.login1.Manager",
@@ -373,8 +677,8 @@ activate_session_id (GDBusConnection *connection,
 }
 
 static gboolean
-get_login_window_session_id (const char  *seat_id,
-                             char       **session_id)
+get_login_window_session_id_for_systemd (const char  *seat_id,
+                                         char       **session_id)
 {
         gboolean   ret;
         int        res, i;
@@ -442,8 +746,8 @@ out:
 }
 
 static gboolean
-goto_login_session (GDBusConnection  *connection,
-                    GError          **error)
+goto_login_session_for_systemd (GDBusConnection  *connection,
+                                GError          **error)
 {
         gboolean        ret;
         int             res;
@@ -497,9 +801,9 @@ goto_login_session (GDBusConnection  *connection,
                 return FALSE;
         }
 
-        res = get_login_window_session_id (seat_id, &session_id);
+        res = get_login_window_session_id_for_systemd (seat_id, &session_id);
         if (res && session_id != NULL) {
-                res = activate_session_id (connection, seat_id, session_id);
+                res = activate_session_id_for_systemd (connection, seat_id, session_id);
 
                 if (res) {
                         ret = TRUE;
@@ -518,6 +822,7 @@ goto_login_session (GDBusConnection  *connection,
 
         return ret;
 }
+#endif
 
 gboolean
 gdm_goto_login_session (GError **error)
@@ -533,7 +838,17 @@ gdm_goto_login_session (GError **error)
                 return FALSE;
         }
 
-        return goto_login_session (connection, error);
+#ifdef WITH_SYSTEMD
+        if (LOGIND_RUNNING()) {
+                return goto_login_session_for_systemd (connection, error);
+        }
+#endif
+
+#ifdef WITH_CONSOLE_KIT
+        return goto_login_session_for_ck (connection, error);
+#else
+        return FALSE;
+#endif
 }
 
 static void
