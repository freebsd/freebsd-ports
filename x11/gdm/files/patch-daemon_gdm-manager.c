--- daemon/gdm-manager.c.orig	2024-05-29 15:50:27 UTC
+++ daemon/gdm-manager.c
@@ -36,7 +36,11 @@
 
 #include <act/act-user-manager.h>
 
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-login.h>
+#elif defined(WITH_CONSOLE_KIT)
+#include <ConsoleKit/sd-login.h>
+#endif
 
 #include "gdm-common.h"
 
@@ -307,6 +311,7 @@ session_unlock (GdmManager *manager,
 
         g_debug ("Unlocking session %s", ssid);
 
+#if defined(WITH_SYSTEMD)
         reply = g_dbus_connection_call_sync (manager->connection,
                                              "org.freedesktop.login1",
                                              "/org/freedesktop/login1",
@@ -324,6 +329,25 @@ session_unlock (GdmManager *manager,
                 g_error_free (error);
                 return FALSE;
         }
+#elif defined(WITH_CONSOLE_KIT)
+        reply = g_dbus_connection_call_sync (manager->connection,
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
 
@@ -380,6 +404,7 @@ is_remote_session (GdmManager  *self,
                    const char  *session_id,
                    GError     **error)
 {
+#ifdef WITH_SYSTEMD
         int ret;
 
         ret = sd_session_is_remote (session_id);
@@ -393,6 +418,27 @@ is_remote_session (GdmManager  *self,
         }
 
         return ret != FALSE;
+#elif defined(WITH_CONSOLE_KIT)
+        char *seat = NULL;
+        int ret;
+        gboolean is_remote;
+
+        ret = sd_session_get_seat (session_id, &seat);
+
+        if (ret < 0 && ret != -ENXIO) {
+                g_debug ("GdmManager: Error while retrieving seat for session %s: %s",
+                         session_id, g_strerror (-ret));
+        }
+
+        if (seat != NULL) {
+                is_remote = FALSE;
+                free (seat);
+        } else {
+                is_remote = TRUE;
+        }
+
+        return is_remote;
+#endif
 }
 
 static char *
@@ -427,6 +473,7 @@ get_tty_for_session_id (const char  *session_id,
 get_tty_for_session_id (const char  *session_id,
                         GError     **error)
 {
+#ifdef WITH_SYSTEMD
         int ret;
         char *tty, *out_tty;
 
@@ -448,6 +495,9 @@ get_tty_for_session_id (const char  *session_id,
         }
 
         return out_tty;
+#elif defined(WITH_CONSOLE_KIT)
+	return NULL;
+#endif
 }
 
 static void
@@ -2101,12 +2151,58 @@ on_user_session_died (GdmSession *session,
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
