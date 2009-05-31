--- daemon/gdm-session-worker.c.orig	2009-04-14 10:01:14.000000000 -0400
+++ daemon/gdm-session-worker.c	2009-05-31 15:52:10.000000000 -0400
@@ -31,6 +31,9 @@
 #include <errno.h>
 #include <grp.h>
 #include <pwd.h>
+#ifdef HAVE_LOGINCAP
+#include <login_cap.h>
+#endif
 
 #include <security/pam_appl.h>
 
@@ -332,7 +335,7 @@ gdm_session_execute (const char *file,
                          * what to search if PATH is unset. POSIX may, dunno.
                          */
 
-                        path = "/bin:/usr/bin:.";
+                        path = "/bin:/usr/bin:/usr/local/bin:.";
                 }
 
                 len = strlen (file) + 1;
@@ -1757,11 +1760,12 @@ gdm_session_worker_start_user_session (G
                 char **environment;
                 char  *home_dir;
                 int    fd;
+#ifdef HAVE_LOGINCAP
+                char *login = worker->priv->username;
+                struct passwd *pwent = getpwnam (login);
+#endif
 
-                if (setuid (worker->priv->uid) < 0) {
-                        g_debug ("GdmSessionWorker: could not reset uid - %s", g_strerror (errno));
-                        _exit (1);
-                }
+                /* Call setsid() before setusercontext() */
 
                 if (setsid () < 0) {
                         g_debug ("GdmSessionWorker: could not set pid '%u' as leader of new session and process group - %s",
@@ -1769,6 +1773,28 @@ gdm_session_worker_start_user_session (G
                         _exit (2);
                 }
 
+#ifdef HAVE_LOGINCAP
+                if (setusercontext (NULL, pwent, pwent->pw_uid,
+                            LOGIN_SETLOGIN | LOGIN_SETPATH |
+                            LOGIN_SETPRIORITY | LOGIN_SETRESOURCES |
+                            LOGIN_SETUMASK | LOGIN_SETUSER |
+                            LOGIN_SETENV) < 0) {
+                        g_debug ("%s: setusercontext () failed for %s. "
+                                  "Aborting.", "gdm_session_worker_start_user_session",
+                                login ? login : "(null)");
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
