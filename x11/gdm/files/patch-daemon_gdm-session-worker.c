--- daemon/gdm-session-worker.c.orig	2010-08-11 13:40:07.000000000 -0400
+++ daemon/gdm-session-worker.c	2011-08-13 23:37:04.000000000 -0400
@@ -31,6 +31,9 @@
 #include <errno.h>
 #include <grp.h>
 #include <pwd.h>
+#ifdef HAVE_LOGINCAP
+#include <login_cap.h>
+#endif
 
 #ifdef  HAVE_LOGINDEVPERM
 #include <libdevinfo.h>
@@ -341,7 +344,7 @@ gdm_session_execute (const char *file,
                          * what to search if PATH is unset. POSIX may, dunno.
                          */
 
-                        path = "/bin:/usr/bin:.";
+                        path = "/bin:/usr/bin:%%LOCALBASE%%/bin:.";
                 }
 
                 len = strlen (file) + 1;
@@ -1035,17 +1038,6 @@ gdm_cache_copy_file (GdmSessionWorker *w
                                    error->message);
                         g_error_free (error);
                  } else {
-                         int res;
-
-                         res = chown (cachefilename,
-                                      worker->priv->uid,
-                                      worker->priv->gid);
-                         if (res == -1) {
-                                 g_warning ("GdmSessionWorker: Error setting owner of cache file: %s",
-                                            g_strerror (errno));
-                         }
-
-                        g_chmod (cachefilename, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
                         g_debug ("Copy successful");
                 }
 
@@ -1183,7 +1175,23 @@ gdm_session_worker_uninitialize_pam (Gdm
                 return;
 
         if (worker->priv->state >= GDM_SESSION_WORKER_STATE_SESSION_OPENED) {
-                gdm_session_worker_cache_userfiles (worker);
+                pid_t pid;
+
+                pid = fork ();
+
+                if (pid == 0) {
+                        if (setuid (worker->priv->uid) < 0) {
+                                g_debug ("GdmSessionWorker: could not reset uid: %s", g_strerror (errno));
+                                _exit (1);
+                        }
+
+                        gdm_session_worker_cache_userfiles (worker);
+                        _exit (0);
+                }
+
+                if (pid > 0) {
+                        gdm_wait_on_pid (pid);
+                }
                 pam_close_session (worker->priv->pam_handle, 0);
                 gdm_session_auditor_report_logout (worker->priv->auditor);
 
@@ -2027,15 +2035,16 @@ gdm_session_worker_start_user_session (G
                 char  *cachedirname;
                 char  *home_dir;
                 int    fd;
+#ifdef HAVE_LOGINCAP
+                char *login = worker->priv->username;
+                struct passwd *pwent = getpwnam (login);
+#endif
 
                 /* Make sure cachedir gets created before we drop to user */
                 cachedirname = gdm_session_worker_create_cachedir (worker);
                 g_free (cachedirname);
 
-                if (setuid (worker->priv->uid) < 0) {
-                        g_debug ("GdmSessionWorker: could not reset uid - %s", g_strerror (errno));
-                        _exit (1);
-                }
+                /* Call setsid() before setusercontext() */
 
                 if (setsid () < 0) {
                         g_debug ("GdmSessionWorker: could not set pid '%u' as leader of new session and process group - %s",
@@ -2043,6 +2052,26 @@ gdm_session_worker_start_user_session (G
                         _exit (2);
                 }
 
+#ifdef HAVE_LOGINCAP
+                if (setusercontext (NULL, pwent, pwent->pw_uid,
+                            LOGIN_SETALL & ~LOGIN_SETGROUP) < 0) {
+                        g_debug ("%s: setusercontext () failed for %s. "
+                                  "Aborting.", "gdm_session_worker_start_user_session",
+                                login ? login : "(null)");
+			_exit (1);
+                }
+
+                /* Propagate PATH environment variable from user context to child processes */
+
+                gdm_session_worker_set_environment_variable (worker, "PATH", getenv ("PATH"));
+
+#else
+                if (setuid (worker->priv->uid) < 0) {
+                        g_debug ("GdmSessionWorker: could not reset uid - %s", g_strerror (errno));
+                        _exit (1);
+                }
+#endif
+
                 environment = gdm_session_worker_get_environment (worker);
 
                 g_assert (geteuid () == getuid ());
