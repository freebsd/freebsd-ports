--- daemon/gdm-manager.c.orig	2022-01-12 14:15:56 UTC
+++ daemon/gdm-manager.c
@@ -36,7 +36,9 @@
 
 #include <act/act-user-manager.h>
 
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-login.h>
+#endif
 
 #include "gdm-common.h"
 
@@ -61,7 +63,7 @@
 #define GDM_MANAGER_PATH          GDM_DBUS_PATH "/Manager"
 #define GDM_MANAGER_DISPLAYS_PATH GDM_DBUS_PATH "/Displays"
 
-#define INITIAL_SETUP_USERNAME "gnome-initial-setup"
+#define INITIAL_SETUP_USERNAME "_gnome-initial-setup"
 #define ALREADY_RAN_INITIAL_SETUP_ON_THIS_BOOT GDM_RUN_DIR "/gdm.ran-initial-setup"
 
 typedef struct
@@ -304,6 +306,7 @@ session_unlock (GdmManager *manager,
 
         g_debug ("Unlocking session %s", ssid);
 
+#if defined(WITH_SYSTEMD)
         reply = g_dbus_connection_call_sync (manager->priv->connection,
                                              "org.freedesktop.login1",
                                              "/org/freedesktop/login1",
@@ -321,6 +324,25 @@ session_unlock (GdmManager *manager,
                 g_error_free (error);
                 return FALSE;
         }
+#elif defined(WITH_CONSOLE_KIT)
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
+                g_debug ("GdmManager: ConsoleKit 'Unlock' %s raised:\n %s\n\n",
+                         g_dbus_error_get_remote_error (error), error->message);
+                g_error_free (error);
+                return FALSE;
+        }
+#endif
 
         g_variant_unref (reply);
 
@@ -436,6 +458,7 @@ static char *
 get_tty_for_session_id (const char  *session_id,
                         GError     **error)
 {
+#ifdef WITH_SYSTEMD
         int ret;
         char *tty, *out_tty;
 
@@ -457,6 +480,9 @@ get_tty_for_session_id (const char  *session_id,
         }
 
         return out_tty;
+#elif defined(WITH_CONSOLE_KIT)
+	return NULL;
+#endif
 }
 
 static void
@@ -609,6 +635,7 @@ switch_to_compatible_user_session (GdmManager *manager
 
         if (existing_session != NULL) {
                 ssid_to_activate = gdm_session_get_session_id (existing_session);
+#ifndef __FreeBSD__
                 if (seat_id != NULL) {
                         res = gdm_activate_session_by_id (manager->priv->connection, seat_id, ssid_to_activate);
                         if (! res) {
@@ -616,6 +643,7 @@ switch_to_compatible_user_session (GdmManager *manager
                                 goto out;
                         }
                 }
+#endif
 
                 res = session_unlock (manager, ssid_to_activate);
                 if (!res) {
@@ -1204,7 +1232,7 @@ display_is_on_seat0 (GdmDisplay *display)
 
         g_object_get (G_OBJECT (display), "seat-id", &seat_id, NULL);
 
-        if (g_strcmp0 (seat_id, "seat0") != 0) {
+        if (g_strcmp0 (seat_id, SEAT_ID) != 0) {
             is_on_seat0 = FALSE;
         }
 
@@ -2019,12 +2047,58 @@ on_user_session_died (GdmSession *session,
         remove_user_session (manager, session);
 }
 
+#ifdef WITH_CONSOLE_KIT
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
+        command = g_strdup_printf ("/usr/local/libexec/ck-get-x11-display-device --display %s",
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
+#endif
+
+static char *
 get_display_device (GdmManager *manager,
                     GdmDisplay *display)
 {
+#ifdef WITH_SYSTEMD
         /* systemd finds the display device out on its own based on the display */
         return NULL;
+#elif defined(WITH_CONSOLE_KIT)
+        return query_ck_for_display_device (manager, display);
+#endif
 }
 
 static void
