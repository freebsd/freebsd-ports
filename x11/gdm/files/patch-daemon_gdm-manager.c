$OpenBSD: patch-daemon_gdm-manager_c,v 1.14 2017/05/10 10:18:15 ajacoutot Exp $

REVERT - OpenBSD does not have a systemd implementation (we need ConsoleKit)
From 21905303afbd508f3bf599ad219c9209413c53a2 Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Wed, 5 Apr 2017 12:11:20 -0400
Subject: manager: stop transient greeter session when done with it

REVERT - OpenBSD does not have a systemd implementation (we need ConsoleKit)
From 22c332baaf8ad6d7082c5b01250bae70934c2fd1 Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Tue, 4 Apr 2017 17:07:04 -0400
Subject: manager: make sure we end up on a login screen

REVERT - OpenBSD does not have a systemd implementation (we need ConsoleKit)
From 1ac67f522f5690c27023d98096ca817f12f7eb88 Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Fri, 12 Jun 2015 13:28:01 -0400
Subject: drop consolekit support

REVERT - OpenBSD does not have a systemd implementation (we need ConsoleKit)
From 9be58c9ec9a3a411492a5182ac4b0d51fdc3a323 Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Fri, 12 Jun 2015 13:48:52 -0400
Subject: require logind support


--- daemon/gdm-manager.c.orig	2017-10-24 21:33:58.000000000 +0200
+++ daemon/gdm-manager.c	2018-01-14 13:33:21.588929000 +0100
@@ -36,7 +36,9 @@
 
 #include <act/act-user-manager.h>
 
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-login.h>
+#endif
 
 #include "gdm-common.h"
 
@@ -63,6 +65,15 @@
 
 #define INITIAL_SETUP_USERNAME "gnome-initial-setup"
 
+#define CK_NAME      "org.freedesktop.ConsoleKit"
+#define CK_PATH      "/org/freedesktop/ConsoleKit"
+#define CK_INTERFACE "org.freedesktop.ConsoleKit"
+
+#define CK_MANAGER_PATH      "/org/freedesktop/ConsoleKit/Manager"
+#define CK_MANAGER_INTERFACE "org.freedesktop.ConsoleKit.Manager"
+#define CK_SEAT_INTERFACE    "org.freedesktop.ConsoleKit.Seat"
+#define CK_SESSION_INTERFACE "org.freedesktop.ConsoleKit.Session"
+
 typedef struct
 {
         GdmManager *manager;
@@ -206,9 +217,10 @@ plymouth_quit_without_transition (void)
 }
 #endif
 
+#ifdef WITH_SYSTEMD
 static char *
-get_session_id_for_pid (pid_t    pid,
-                        GError **error)
+get_session_id_for_pid_systemd (pid_t    pid,
+                                GError **error)
 {
         char *session, *gsession;
         int ret;
@@ -233,11 +245,61 @@ get_session_id_for_pid (pid_t    pid,
                 return NULL;
         }
 }
+#endif
 
+#ifdef WITH_CONSOLE_KIT
+static char *
+get_session_id_for_pid_consolekit (GDBusConnection  *connection,
+                                   pid_t             pid,
+                                   GError          **error)
+{
+        GVariant *reply;
+        char *retval;
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             "org.freedesktop.ConsoleKit",
+                                             "/org/freedesktop/ConsoleKit/Manager",
+                                             "org.freedesktop.ConsoleKit.Manager",
+                                             "GetSessionForUnixProcess",
+                                             g_variant_new ("(u)", pid),
+                                             G_VARIANT_TYPE ("(o)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL, error);
+        if (reply == NULL) {
+                return NULL;
+        }
+
+        g_variant_get (reply, "(o)", &retval);
+        g_variant_unref (reply);
+
+        return retval;
+}
+#endif
+
+static char *
+get_session_id_for_pid (GDBusConnection  *connection,
+                        pid_t             pid,
+                        GError          **error)
+{
+#ifdef WITH_SYSTEMD
+        if (LOGIND_RUNNING()) {
+                return get_session_id_for_pid_systemd (pid, error);
+        }
+#endif
+
+#ifdef WITH_CONSOLE_KIT
+        return get_session_id_for_pid_consolekit (connection, pid, error);
+#endif
+
+        return NULL;
+}
+
+#ifdef WITH_SYSTEMD
 static gboolean
-get_uid_for_session_id (const char  *session_id,
-                        uid_t       *uid,
-                        GError     **error)
+get_uid_for_systemd_session_id (const char  *session_id,
+                                uid_t       *uid,
+                                GError     **error)
 {
         int ret;
 
@@ -254,8 +316,62 @@ get_uid_for_session_id (const char  *session_id,
 
         return TRUE;
 }
+#endif
 
+#ifdef WITH_CONSOLE_KIT
 static gboolean
+get_uid_for_consolekit_session_id (GDBusConnection  *connection,
+                                   const char       *session_id,
+                                   uid_t            *out_uid,
+                                   GError          **error)
+{
+        GVariant *reply;
+        guint32 uid;
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             "org.freedesktop.ConsoleKit",
+                                             session_id,
+                                             "org.freedesktop.ConsoleKit.Session",
+                                             "GetUnixUser",
+                                             NULL,
+                                             G_VARIANT_TYPE ("(u)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL,
+                                             error);
+        if (reply == NULL) {
+                return FALSE;
+        }
+
+        g_variant_get (reply, "(u)", &uid);
+        g_variant_unref (reply);
+
+        *out_uid = (uid_t) uid;
+
+        return TRUE;
+}
+#endif
+
+static gboolean
+get_uid_for_session_id (GDBusConnection  *connection,
+                        const char       *session_id,
+                        uid_t            *uid,
+                        GError          **error)
+{
+#ifdef WITH_SYSTEMD
+        if (LOGIND_RUNNING()) {
+                return get_uid_for_systemd_session_id (session_id, uid, error);
+        }
+#endif
+
+#ifdef WITH_CONSOLE_KIT
+        return get_uid_for_consolekit_session_id (connection, session_id, uid, error);
+#endif
+
+        return FALSE;
+}
+
+static gboolean
 lookup_by_session_id (const char *id,
                       GdmDisplay *display,
                       gpointer    user_data)
@@ -267,11 +383,51 @@ lookup_by_session_id (const char *id,
         return g_strcmp0 (current, looking_for) == 0;
 }
 
+#ifdef WITH_CONSOLE_KIT
 static gboolean
-is_login_session (GdmManager  *self,
-                  const char  *session_id,
-                  GError     **error)
+is_consolekit_login_session (GdmManager       *self,
+                             GDBusConnection  *connection,
+                             const char       *session_id,
+                             GError          **error)
 {
+        GVariant *reply;
+        char *session_type = NULL;
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             "org.freedesktop.ConsoleKit",
+                                             session_id,
+                                             "org.freedesktop.ConsoleKit.Session",
+                                             "GetSessionType",
+                                             NULL,
+                                             G_VARIANT_TYPE ("(s)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL,
+                                             error);
+        if (reply == NULL) {
+                return FALSE;
+        }
+
+        g_variant_get (reply, "(s)", &session_type);
+        g_variant_unref (reply);
+
+        if (g_strcmp0 (session_type, "LoginWindow") != 0) {
+                g_free (session_type);
+
+                return FALSE;
+        }
+
+        g_free (session_type);
+        return TRUE;
+}
+#endif
+
+#ifdef WITH_SYSTEMD
+static gboolean
+is_systemd_login_session (GdmManager  *self,
+                          const char  *session_id,
+                          GError     **error)
+{
         char *session_class = NULL;
         int ret;
 
@@ -295,12 +451,33 @@ is_login_session (GdmManager  *self,
         g_free (session_class);
         return TRUE;
 }
+#endif
 
 static gboolean
-activate_session_id (GdmManager *manager,
-                     const char *seat_id,
-                     const char *session_id)
+is_login_session (GdmManager       *self,
+                  GDBusConnection  *connection,
+                  const char       *session_id,
+                  GError          **error)
 {
+#ifdef WITH_SYSTEMD
+        if (LOGIND_RUNNING()) {
+                return is_systemd_login_session (self, session_id, error);
+        }
+#endif
+
+#ifdef WITH_CONSOLE_KIT
+        return is_consolekit_login_session (self, connection, session_id, error);
+#endif
+
+        return FALSE;
+}
+
+#ifdef WITH_SYSTEMD
+static gboolean
+activate_session_id_for_systemd (GdmManager   *manager,
+                                 const char *seat_id,
+                                 const char *session_id)
+{
         GError *error = NULL;
         GVariant *reply;
 
@@ -326,16 +503,75 @@ activate_session_id (GdmManager *manager,
 
         return TRUE;
 }
+#endif
 
+#ifdef WITH_CONSOLE_KIT
 static gboolean
-session_unlock (GdmManager *manager,
-                const char *ssid)
+activate_session_id_for_ck (GdmManager *manager,
+                            const char *seat_id,
+                            const char *session_id)
 {
         GError *error = NULL;
         GVariant *reply;
 
-        g_debug ("Unlocking session %s", ssid);
+        reply = g_dbus_connection_call_sync (manager->priv->connection,
+                                             CK_NAME,
+                                             seat_id,
+                                             "org.freedesktop.ConsoleKit.Seat",
+                                             "ActivateSession",
+                                             g_variant_new ("(o)", session_id),
+                                             NULL, /* expected reply */
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL,
+                                             &error);
+        if (reply == NULL) {
+                g_debug ("GdmManager: ConsoleKit %s raised:\n %s\n\n",
+                         g_dbus_error_get_remote_error (error), error->message);
+                g_error_free (error);
 
+                /* It is very likely that the "error" just reported is
+                 * that the session is already active.  Unfortunately,
+                 * ConsoleKit doesn't use proper error codes and it
+                 * translates the error message, so we have no real way
+                 * to detect this case...
+                 */
+                return TRUE;
+        }
+
+        g_variant_unref (reply);
+
+        return TRUE;
+}
+#endif
+
+static gboolean
+activate_session_id (GdmManager *manager,
+                     const char *seat_id,
+                     const char *session_id)
+{
+
+#ifdef WITH_SYSTEMD
+        if (LOGIND_RUNNING()) {
+                return activate_session_id_for_systemd (manager, seat_id, session_id);
+        }
+#endif
+
+#ifdef WITH_CONSOLE_KIT
+        return activate_session_id_for_ck (manager, seat_id, session_id);
+#else
+        return FALSE;
+#endif
+}
+
+#ifdef WITH_SYSTEMD
+static gboolean
+session_unlock_for_systemd (GdmManager *manager,
+                            const char *ssid)
+{
+        GError *error = NULL;
+        GVariant *reply;
+
         reply = g_dbus_connection_call_sync (manager->priv->connection,
                                              "org.freedesktop.login1",
                                              "/org/freedesktop/login1",
@@ -358,7 +594,60 @@ session_unlock (GdmManager *manager,
 
         return TRUE;
 }
+#endif
 
+#ifdef WITH_CONSOLE_KIT
+static gboolean
+session_unlock_for_ck (GdmManager *manager,
+                       const char *ssid)
+{
+        GError *error = NULL;
+        GVariant *reply;
+
+        reply = g_dbus_connection_call_sync (manager->priv->connection,
+                                             CK_NAME,
+                                             ssid,
+                                             CK_SESSION_INTERFACE,
+                                             "Unlock",
+                                             NULL, /* parameters */
+                                             NULL, /* expected reply */
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL,
+                                             &error);
+        if (reply == NULL) {
+                g_debug ("GdmManager: ConsoleKit %s raised:\n %s\n\n",
+                         g_dbus_error_get_remote_error (error), error->message);
+                g_error_free (error);
+                return FALSE;
+        }
+
+        g_variant_unref (reply);
+
+        return TRUE;
+}
+#endif
+
+static gboolean
+session_unlock (GdmManager *manager,
+                const char *ssid)
+{
+
+        g_debug ("Unlocking session %s", ssid);
+
+#ifdef WITH_SYSTEMD
+        if (LOGIND_RUNNING()) {
+                return session_unlock_for_systemd (manager, ssid);
+        }
+#endif
+
+#ifdef WITH_CONSOLE_KIT
+        return session_unlock_for_ck (manager, ssid);
+#else
+        return TRUE;
+#endif
+}
+
 static GdmSession *
 find_session_for_user_on_seat (GdmManager *manager,
                                const char *username,
@@ -389,11 +678,44 @@ find_session_for_user_on_seat (GdmManager *manager,
         return NULL;
 }
 
+#ifdef WITH_CONSOLE_KIT
 static gboolean
-is_remote_session (GdmManager  *self,
-                   const char  *session_id,
-                   GError     **error)
+is_consolekit_remote_session (GdmManager       *self,
+                             GDBusConnection  *connection,
+                             const char       *session_id,
+                             GError          **error)
 {
+        GVariant *reply;
+        gboolean is_remote;
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             "org.freedesktop.ConsoleKit",
+                                             session_id,
+                                             "org.freedesktop.ConsoleKit.Session",
+                                             "IsLocal",
+                                             NULL,
+                                             G_VARIANT_TYPE ("(b)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL,
+                                             error);
+        if (reply == NULL) {
+                return FALSE;
+        }
+
+        g_variant_get (reply, "(b)", &is_remote);
+        g_variant_unref (reply);
+
+        return is_remote;
+}
+#endif
+
+#ifdef WITH_SYSTEMD
+static gboolean
+is_systemd_remote_session (GdmManager  *self,
+                           const char  *session_id,
+                           GError     **error)
+{
         char *seat;
         int ret;
         gboolean is_remote;
@@ -418,10 +740,31 @@ is_remote_session (GdmManager  *self,
 
         return is_remote;
 }
+#endif
 
+static gboolean
+is_remote_session (GdmManager       *self,
+                  GDBusConnection  *connection,
+                  const char       *session_id,
+                  GError          **error)
+{
+#ifdef WITH_SYSTEMD
+        if (LOGIND_RUNNING()) {
+                return is_systemd_remote_session (self, session_id, error);
+        }
+#endif
+
+#ifdef WITH_CONSOLE_KIT
+        return is_consolekit_remote_session (self, connection, session_id, error);
+#endif
+
+        return FALSE;
+}
+
+#ifdef WITH_SYSTEMD
 static char *
-get_seat_id_for_session_id (const char  *session_id,
-                            GError     **error)
+get_seat_id_for_systemd_session_id (const char  *session_id,
+                                    GError     **error)
 {
         int ret;
         char *seat, *out_seat;
@@ -446,11 +789,62 @@ get_seat_id_for_session_id (const char  *session_id,
 
         return out_seat;
 }
+#endif
 
+#ifdef WITH_CONSOLE_KIT
 static char *
-get_tty_for_session_id (const char  *session_id,
-                        GError     **error)
+get_seat_id_for_consolekit_session_id (GDBusConnection  *connection,
+                                       const char       *session_id,
+                                       GError          **error)
 {
+        GVariant *reply;
+        char *retval;
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             "org.freedesktop.ConsoleKit",
+                                             session_id,
+                                             "org.freedesktop.ConsoleKit.Session",
+                                             "GetSeatId",
+                                             NULL,
+                                             G_VARIANT_TYPE ("(o)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL,
+                                             error);
+        if (reply == NULL) {
+                return NULL;
+        }
+
+        g_variant_get (reply, "(o)", &retval);
+        g_variant_unref (reply);
+
+        return retval;
+}
+#endif
+
+static char *
+get_seat_id_for_session_id (GDBusConnection  *connection,
+                            const char       *session_id,
+                            GError          **error)
+{
+#ifdef WITH_SYSTEMD
+        if (LOGIND_RUNNING()) {
+                return get_seat_id_for_systemd_session_id (session_id, error);
+        }
+#endif
+
+#ifdef WITH_CONSOLE_KIT
+        return get_seat_id_for_consolekit_session_id (connection, session_id, error);
+#endif
+
+        return NULL;
+}
+
+#ifdef WITH_SYSTEMD
+static char *
+get_tty_for_systemd_session_id (const char  *session_id,
+                                GError     **error)
+{
         int ret;
         char *tty, *out_tty;
 
@@ -473,7 +867,21 @@ get_tty_for_session_id (const char  *session_id,
 
         return out_tty;
 }
+#endif
 
+static char *
+get_tty_for_session_id (const char  *session_id,
+                        GError     **error)
+{
+#ifdef WITH_SYSTEMD
+        if (LOGIND_RUNNING()) {
+                return get_tty_for_systemd_session_id (session_id, error);
+        }
+#endif
+
+        return NULL;
+}
+
 static void
 get_display_and_details_for_bus_sender (GdmManager       *self,
                                         GDBusConnection  *connection,
@@ -516,7 +924,7 @@ get_display_and_details_for_bus_sender (GdmManager    
                 goto out;
         }
 
-        session_id = get_session_id_for_pid (pid, &error);
+        session_id = get_session_id_for_pid (connection, pid, &error);
 
         if (session_id == NULL) {
                 g_debug ("GdmManager: Error while retrieving session id for sender: %s",
@@ -530,7 +938,7 @@ get_display_and_details_for_bus_sender (GdmManager    
         }
 
         if (out_is_login_screen != NULL) {
-                *out_is_login_screen = is_login_session (self, session_id, &error);
+                *out_is_login_screen = is_login_session (self, connection, session_id, &error);
 
                 if (error != NULL) {
                         g_debug ("GdmManager: Error while checking if sender is login screen: %s",
@@ -540,7 +948,7 @@ get_display_and_details_for_bus_sender (GdmManager    
                 }
         }
 
-        if (!get_uid_for_session_id (session_id, &session_uid, &error)) {
+        if (!get_uid_for_session_id (connection, session_id, &session_uid, &error)) {
                 g_debug ("GdmManager: Error while retrieving uid for session: %s",
                          error->message);
                 g_error_free (error);
@@ -557,7 +965,7 @@ get_display_and_details_for_bus_sender (GdmManager    
         }
 
         if (out_seat_id != NULL) {
-                *out_seat_id = get_seat_id_for_session_id (session_id, &error);
+                *out_seat_id = get_seat_id_for_session_id (connection, session_id, &error);
 
                 if (error != NULL) {
                         g_debug ("GdmManager: Error while retrieving seat id for session: %s",
@@ -567,7 +975,7 @@ get_display_and_details_for_bus_sender (GdmManager    
         }
 
         if (out_is_remote != NULL) {
-                *out_is_remote = is_remote_session (self, session_id, &error);
+                *out_is_remote = is_remote_session (self, connection, session_id, &error);
 
                 if (error != NULL) {
                         g_debug ("GdmManager: Error while retrieving remoteness for session: %s",
@@ -725,29 +1133,6 @@ out:
         return recorded;
 }
 
-static GdmSession *
-find_user_session_for_display (GdmManager *self,
-                               GdmDisplay *display)
-{
-
-        GList *node = self->priv->user_sessions;
-
-        while (node != NULL) {
-                GdmSession *session = node->data;
-                GdmDisplay *candidate_display;
-                GList *next_node = node->next;
-
-                candidate_display = get_display_for_user_session (session);
-
-                if (candidate_display == display)
-                        return session;
-
-                node = next_node;
-        }
-
-        return NULL;
-}
-
 static gboolean
 gdm_manager_handle_register_display (GdmDBusManager        *manager,
                                      GDBusMethodInvocation *invocation,
@@ -787,7 +1172,7 @@ gdm_manager_handle_register_display (GdmDBusManager   
                 }
         }
 
-        session = find_user_session_for_display (self, display);
+        session = get_user_session_for_display (display);
 
         if (session != NULL) {
                 GPid pid;
@@ -961,7 +1346,8 @@ on_reauthentication_client_rejected (GdmSession       
                  * same audit session, ignore it since it doesn't "own" the
                  * reauthentication session
                  */
-                client_session_id = get_session_id_for_pid (pid_of_client,
+                client_session_id = get_session_id_for_pid (self->priv->connection,
+                                                            pid_of_client,
                                                             NULL);
                 session_id = g_object_get_data (G_OBJECT (session), "caller-session-id");
 
@@ -1173,16 +1559,20 @@ static gboolean
 display_is_on_seat0 (GdmDisplay *display)
 {
         gboolean is_on_seat0 = TRUE;
-        char *seat_id = NULL;
 
-        g_object_get (G_OBJECT (display), "seat-id", &seat_id, NULL);
+#ifdef WITH_SYSTEMD
+        if (LOGIND_RUNNING()) {
+                char *seat_id = NULL;
 
-        if (g_strcmp0 (seat_id, "seat0") != 0) {
-            is_on_seat0 = FALSE;
-        }
+                g_object_get (G_OBJECT (display), "seat-id", &seat_id, NULL);
 
-        g_free (seat_id);
+                if (g_strcmp0 (seat_id, "seat0") != 0) {
+                        is_on_seat0 = FALSE;
+                }
 
+                g_free (seat_id);
+        }
+#endif
         return is_on_seat0;
 }
 
@@ -1320,133 +1710,6 @@ maybe_start_pending_initial_login (GdmManager *manager
         g_free (user_session_seat_id);
 }
 
-static gboolean
-get_login_window_session_id (const char  *seat_id,
-                             char       **session_id)
-{
-        gboolean   ret;
-        int        res, i;
-        char     **sessions;
-        char      *service_id;
-        char      *service_class;
-        char      *state;
-
-        res = sd_seat_get_sessions (seat_id, &sessions, NULL, NULL);
-        if (res < 0) {
-                g_debug ("Failed to determine sessions: %s", strerror (-res));
-                return FALSE;
-        }
-
-        if (sessions == NULL || sessions[0] == NULL) {
-                *session_id = NULL;
-                ret = TRUE;
-                goto out;
-        }
-
-        for (i = 0; sessions[i]; i ++) {
-
-                res = sd_session_get_class (sessions[i], &service_class);
-                if (res < 0) {
-                        g_debug ("failed to determine class of session %s: %s", sessions[i], strerror (-res));
-                        ret = FALSE;
-                        goto out;
-                }
-
-                if (strcmp (service_class, "greeter") != 0) {
-                        free (service_class);
-                        continue;
-                }
-
-                free (service_class);
-
-                ret = sd_session_get_state (sessions[i], &state);
-                if (ret < 0) {
-                        g_debug ("failed to determine state of session %s: %s", sessions[i], strerror (-res));
-                        ret = FALSE;
-                        goto out;
-                }
-
-                if (g_strcmp0 (state, "closing") == 0) {
-                        free (state);
-                        continue;
-                }
-                free (state);
-
-                res = sd_session_get_service (sessions[i], &service_id);
-                if (res < 0) {
-                        g_debug ("failed to determine service of session %s: %s", sessions[i], strerror (-res));
-                        ret = FALSE;
-                        goto out;
-                }
-
-                if (strcmp (service_id, "gdm-launch-environment") == 0) {
-                        *session_id = g_strdup (sessions[i]);
-                        ret = TRUE;
-
-                        free (service_id);
-                        goto out;
-                }
-
-                free (service_id);
-        }
-
-        *session_id = NULL;
-        ret = TRUE;
-
-out:
-        if (sessions) {
-                for (i = 0; sessions[i]; i ++) {
-                        free (sessions[i]);
-                }
-
-                free (sessions);
-        }
-
-        return ret;
-}
-
-static void
-activate_login_window_session_on_seat (GdmManager *self,
-                                       const char *seat_id)
-{
-        char *session_id;
-
-        if (!get_login_window_session_id (seat_id, &session_id)) {
-                return;
-        }
-
-        activate_session_id (self, seat_id, session_id);
-}
-
-static void
-maybe_activate_other_session (GdmManager *self,
-                              GdmDisplay *old_display)
-{
-        char *seat_id = NULL;
-        char *session_id;
-        int ret;
-
-        g_object_get (G_OBJECT (old_display),
-                      "seat-id", &seat_id,
-                      NULL);
-
-        ret = sd_seat_get_active (seat_id, &session_id, NULL);
-
-        if (ret == 0) {
-                GdmDisplay *display;
-
-                display = gdm_display_store_find (self->priv->display_store,
-                                                  lookup_by_session_id,
-                                                  (gpointer) session_id);
-
-                if (display == NULL) {
-                        activate_login_window_session_on_seat (self, seat_id);
-                }
-        }
-
-        g_free (seat_id);
-}
-
 static const char *
 get_username_for_greeter_display (GdmManager *manager,
                                   GdmDisplay *display)
@@ -1692,7 +1955,6 @@ on_display_status_changed (GdmDisplay *display,
                                 manager->priv->ran_once = TRUE;
                         }
                         maybe_start_pending_initial_login (manager, display);
-                        maybe_activate_other_session (manager, display);
                         break;
                 default:
                         break;
@@ -2027,11 +2289,57 @@ on_user_session_died (GdmSession *session,
 }
 
 static char *
+query_ck_for_display_device (GdmManager *manager,
+                             GdmDisplay *display)
+{
+        char    *out;
+        char    *command;
+        char    *display_name = NULL;
+        int      status;
+        gboolean res;
+        GError  *error;
+
+        g_object_get (G_OBJECT (display),
+                      "x11-display-name", &display_name,
+                      NULL);
+
+        error = NULL;
+        command = g_strdup_printf (CONSOLEKIT_DIR "/ck-get-x11-display-device --display %s",
+                                   display_name);
+        g_free (display_name);
+
+        g_debug ("GdmManager: Running helper %s", command);
+        out = NULL;
+        res = g_spawn_command_line_sync (command,
+                                         &out,
+                                         NULL,
+                                         &status,
+                                         &error);
+        if (! res) {
+                g_warning ("GdmManager: Could not run helper %s: %s", command, error->message);
+                g_error_free (error);
+        } else {
+                out = g_strstrip (out);
+                g_debug ("GdmManager: Got tty: '%s'", out);
+        }
+
+        g_free (command);
+
+        return out;
+}
+
+static char *
 get_display_device (GdmManager *manager,
                     GdmDisplay *display)
 {
-        /* systemd finds the display device out on its own based on the display */
-        return NULL;
+#ifdef WITH_SYSTEMD
+        if (LOGIND_RUNNING()) {
+                /* systemd finds the display device out on its own based on the display */
+                return NULL;
+        }
+#endif
+
+        return query_ck_for_display_device (manager, display);
 }
 
 static void
@@ -2040,25 +2348,6 @@ on_session_reauthenticated (GdmSession *session,
                             GdmManager *manager)
 {
         gboolean fail_if_already_switched = FALSE;
-
-        if (gdm_session_get_display_mode (session) == GDM_SESSION_DISPLAY_MODE_REUSE_VT) {
-                const char *seat_id;
-                char *session_id;
-
-                seat_id = gdm_session_get_display_seat_id (session);
-                if (get_login_window_session_id (seat_id, &session_id)) {
-                        GdmDisplay *display = gdm_display_store_find (manager->priv->display_store,
-                                                                      lookup_by_session_id,
-                                                                      (gpointer) session_id);
-
-                        if (display != NULL) {
-                                gdm_display_stop_greeter_session (display);
-                                gdm_display_unmanage (display);
-                                gdm_display_finish (display);
-                        }
-                        g_free (session_id);
-                }
-        }
 
         /* There should already be a session running, so jump to its
          * VT. In the event we're already on the right VT, (i.e. user
