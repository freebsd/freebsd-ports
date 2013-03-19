--- daemon/gdm-session-worker.c.orig	2011-06-02 09:50:17.000000000 -0500
+++ daemon/gdm-session-worker.c	2011-06-24 17:59:50.000000000 -0500
@@ -31,6 +31,9 @@
 #include <errno.h>
 #include <grp.h>
 #include <pwd.h>
+#ifdef HAVE_LOGINCAP
+#include <login_cap.h>
+#endif
 
 #ifdef  HAVE_LOGINDEVPERM
 #include <libdevinfo.h>
@@ -341,7 +344,7 @@
                          * what to search if PATH is unset. POSIX may, dunno.
                          */
 
-                        path = "/bin:/usr/bin:.";
+                        path = "/bin:/usr/bin:%%LOCALBASE%%/bin:.";
                 }
 
                 len = strlen (file) + 1;
@@ -2032,15 +2035,16 @@
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
@@ -2048,6 +2052,25 @@
                         _exit (2);
                 }
 
+#ifdef HAVE_LOGINCAP
+                if (setusercontext (NULL, pwent, pwent->pw_uid,
+                            LOGIN_SETALL & ~LOGIN_SETGROUP) < 0) {
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
