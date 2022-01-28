--- daemon/gdm-server.c.orig	2022-01-28 21:55:35 UTC
+++ daemon/gdm-server.c
@@ -43,7 +43,9 @@
 #include <linux/vt.h>
 #endif
 
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-daemon.h>
+#endif
 
 #ifdef ENABLE_SYSTEMD_JOURNAL
 #include <systemd/sd-journal.h>
@@ -84,6 +86,9 @@ struct _GdmServer
         char    *auth_file;
 
         guint    child_watch_id;
+#ifndef HAVE_SIGWAITINFO
+        guint    sigusr1_id;
+#endif
 
         gboolean is_initial;
 };
@@ -114,13 +119,60 @@ static void     gdm_server_finalize     (GObject      
 
 G_DEFINE_TYPE (GdmServer, gdm_server, G_TYPE_OBJECT)
 
+#ifdef WITH_CONSOLE_KIT
+static char *
+gdm_server_query_ck_for_display_device (GdmServer *server)
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
+        command = g_strdup_printf ("/usr/local/libexec/ck-get-x11-display-device --display %s",
+                                   server->display_name);
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
+#endif
+
 char *
 gdm_server_get_display_device (GdmServer *server)
 {
+#if defined(WITH_SYSTEMD)
         /* systemd finds the display device out on its own based on the display */
         return NULL;
+#elif defined(WITH_CONSOLE_KIT)
+        if (server->display_device == NULL) {
+                server->display_device =
+                    gdm_server_query_ck_for_display_device (server);
+                g_object_notify (G_OBJECT (server), "display-device");
+        }
+        return g_strdup (server->display_device);
+#endif
 }
 
+#ifdef HAVE_SIGWAITINFO
 static void
 gdm_server_ready (GdmServer *server)
 {
@@ -133,7 +185,26 @@ gdm_server_ready (GdmServer *server)
 
         g_signal_emit (server, signals[READY], 0);
 }
+#else
+static gboolean
+gdm_server_ready (gpointer user_data)
+{
+        GdmServer *server = user_data;
 
+        g_debug ("GdmServer: Got USR1 from X server - emitting READY");
+
+        gdm_run_script (GDMCONFDIR "/Init", GDM_USERNAME,
+                        server->display_name,
+                        NULL, /* hostname */
+                        server->auth_file);
+
+        g_signal_emit (server, signals[READY], 0);
+
+        return FALSE;
+}
+#endif
+
+#ifdef HAVE_SIGWAITINFO
 static GSList *active_servers;
 static gboolean sigusr1_thread_running;
 static GCond sigusr1_thread_cond;
@@ -199,6 +270,7 @@ gdm_server_launch_sigusr1_thread_if_needed (void)
                 g_mutex_unlock (&sigusr1_thread_mutex);
         }
 }
+#endif
 
 static void
 gdm_server_init_command (GdmServer *server)
@@ -307,10 +379,12 @@ gdm_server_resolve_command_line (GdmServer  *server,
                 argv[len++] = g_strdup (server->auth_file);
         }
 
+#ifdef WITH_SYSTEMD
         if (server->display_seat_id != NULL) {
                 argv[len++] = g_strdup ("-seat");
                 argv[len++] = g_strdup (server->display_seat_id);
         }
+#endif
 
         /* If we were compiled with Xserver >= 1.17 we need to specify
          * '-listen tcp' as the X server dosen't listen on tcp sockets
@@ -656,11 +730,13 @@ server_child_watch (GPid       pid,
         g_object_unref (server);
 }
 
+#ifdef HAVE_SIGWAITINFO
 static void
 prune_active_servers_list (GdmServer *server)
 {
         active_servers = g_slist_remove (active_servers, server);
 }
+#endif
 
 static gboolean
 gdm_server_spawn (GdmServer    *server,
@@ -699,6 +775,7 @@ gdm_server_spawn (GdmServer    *server,
         g_debug ("GdmServer: Starting X server process: %s", freeme);
         g_free (freeme);
 
+#ifdef HAVE_SIGWAITINFO
         active_servers = g_slist_append (active_servers, server);
 
         g_object_weak_ref (G_OBJECT (server),
@@ -707,6 +784,7 @@ gdm_server_spawn (GdmServer    *server,
                            server);
 
         gdm_server_launch_sigusr1_thread_if_needed ();
+#endif
 
         if (!g_spawn_async_with_pipes (NULL,
                                        argv,
@@ -1044,6 +1122,9 @@ gdm_server_init (GdmServer *server)
         server->pid = -1;
 
         server->log_dir = g_strdup (LOGDIR);
+#ifndef HAVE_SIGWAITINFO
+        server->sigusr1_id = g_unix_signal_add (SIGUSR1, gdm_server_ready, server);
+#endif
 }
 
 static void
@@ -1055,6 +1136,11 @@ gdm_server_finalize (GObject *object)
         g_return_if_fail (GDM_IS_SERVER (object));
 
         server = GDM_SERVER (object);
+
+#ifndef HAVE_SIGWAITINFO
+        if (server->sigusr1_id > 0)
+                g_source_remove (server->sigusr1_id);
+#endif
 
         gdm_server_stop (server);
 
