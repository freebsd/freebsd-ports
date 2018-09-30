--- daemon/gdm-server.c.orig	2017-05-05 16:40:44.000000000 +0200
+++ daemon/gdm-server.c	2017-06-08 10:39:30.725180000 +0200
@@ -43,7 +43,9 @@
 #include <linux/vt.h>
 #endif
 
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-daemon.h>
+#endif
 
 #ifdef ENABLE_SYSTEMD_JOURNAL
 #include <systemd/sd-journal.h>
@@ -122,23 +124,65 @@
 
 G_DEFINE_TYPE (GdmServer, gdm_server, G_TYPE_OBJECT)
 
+static char *
+_gdm_server_query_ck_for_display_device (GdmServer *server)
+{
+        char    *out;
+        char    *command;
+        int      status;
+        gboolean res;
+        GError  *error;
+
+        g_return_val_if_fail (GDM_IS_SERVER (server), NULL);
+
+        error = NULL;
+        command = g_strdup_printf (CONSOLEKIT_DIR "/ck-get-x11-display-device --display %s",
+                                   server->priv->display_name);
+
+        g_debug ("GdmServer: Running helper %s", command);
+        out = NULL;
+        res = g_spawn_command_line_sync (command,
+                                         &out,
+                                         NULL,
+                                         &status,
+                                         &error);
+        if (! res) {
+                g_warning ("Could not run helper: %s", error->message);
+                g_error_free (error);
+        } else {
+                out = g_strstrip (out);
+                g_debug ("GdmServer: Got tty: '%s'", out);
+        }
+
+        g_free (command);
+
+        return out;
+}
+
 char *
 gdm_server_get_display_device (GdmServer *server)
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
+        if (server->priv->display_device == NULL) {
+                server->priv->display_device =
+                    _gdm_server_query_ck_for_display_device (server);
+
+                g_object_notify (G_OBJECT (server), "display-device");
+        }
+
+        return g_strdup (server->priv->display_device);
 }
 
 static void
 gdm_server_ready (GdmServer *server)
 {
         g_debug ("GdmServer: Got USR1 from X server - emitting READY");
-
-        gdm_run_script (GDMCONFDIR "/Init", GDM_USERNAME,
-                        server->priv->display_name,
-                        NULL, /* hostname */
-                        server->priv->auth_file);
-
         g_signal_emit (server, signals[READY], 0);
 }
 
@@ -226,8 +270,10 @@
                 debug_options = "";
         }
 
-#define X_SERVER_ARG_FORMAT " -background none -noreset -verbose %s%s"
+        #define X_SERVER_ARG_FORMAT " -background none -noreset -verbose %s%s"
 
+#ifdef WITH_SYSTEMD
+
         /* This is a temporary hack to work around the fact that XOrg
          * currently lacks support for multi-seat hotplugging for
          * display devices. This bit should be removed as soon as XOrg
@@ -242,6 +288,10 @@
          * wasn't booted using systemd, or b) the wrapper tool is
          * missing, or c) we are running for the main seat 'seat0'. */
 
+        if (!LOGIND_RUNNING()) {
+                goto fallback;
+        }
+
 #ifdef ENABLE_SYSTEMD_JOURNAL
         /* For systemd, we don't have a log file but instead log to stdout,
            so set it to the xserver's built-in default verbosity */
@@ -264,8 +314,9 @@
         return;
 
 fallback:
-        server->priv->command = g_strdup_printf (X_SERVER X_SERVER_ARG_FORMAT, verbosity, debug_options);
+#endif
 
+        server->priv->command = g_strdup_printf (X_SERVER X_SERVER_ARG_FORMAT, verbosity, debug_options);
 }
 
 static gboolean
@@ -315,10 +366,12 @@
                 argv[len++] = g_strdup (server->priv->auth_file);
         }
 
-        if (server->priv->display_seat_id != NULL) {
+#ifdef WITH_SYSTEMD
+        if (LOGIND_RUNNING() && server->priv->display_seat_id != NULL) {
                 argv[len++] = g_strdup ("-seat");
                 argv[len++] = g_strdup (server->priv->display_seat_id);
         }
+#endif
 
         /* If we were compiled with Xserver >= 1.17 we need to specify
          * '-listen tcp' as the X server dosen't listen on tcp sockets
@@ -657,18 +710,14 @@
                 g_signal_emit (server, signals [DIED], 0, num);
         }
 
+        active_servers = g_slist_remove (active_servers, server);
+
         g_spawn_close_pid (server->priv->pid);
         server->priv->pid = -1;
 
         g_object_unref (server);
 }
 
-static void
-prune_active_servers_list (GdmServer *server)
-{
-        active_servers = g_slist_remove (active_servers, server);
-}
-
 static gboolean
 gdm_server_spawn (GdmServer    *server,
                   const char   *vtarg,
@@ -707,11 +756,6 @@
         g_free (freeme);
 
         active_servers = g_slist_append (active_servers, server);
-
-        g_object_weak_ref (G_OBJECT (server),
-                           (GWeakNotify)
-                           prune_active_servers_list,
-                           server);
 
         gdm_server_launch_sigusr1_thread_if_needed ();
 
