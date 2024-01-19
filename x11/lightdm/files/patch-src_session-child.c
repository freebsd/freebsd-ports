--- src/session-child.c.orig	2021-04-12 04:52:50 UTC
+++ src/session-child.c
@@ -13,9 +13,11 @@
 #include <grp.h>
 #include <glib.h>
 #include <security/pam_appl.h>
-#include <utmp.h>
 #include <utmpx.h>
 #include <sys/mman.h>
+#if HAVE_SETUSERCONTEXT
+#include <login_cap.h>
+#endif
 
 #if HAVE_LIBAUDIT
 #include <libaudit.h>
@@ -193,28 +195,6 @@ read_xauth (void)
     return x_authority_new (x_authority_family, x_authority_address, x_authority_address_length, x_authority_number, x_authority_name, x_authority_data, x_authority_data_length);
 }
 
-/* GNU provides this but we can't rely on that so let's make our own version */
-static void
-updwtmpx (const gchar *wtmp_file, struct utmpx *ut)
-{
-    struct utmp u;
-    memset (&u, 0, sizeof (u));
-    u.ut_type = ut->ut_type;
-    u.ut_pid = ut->ut_pid;
-    if (ut->ut_line)
-        strncpy (u.ut_line, ut->ut_line, sizeof (u.ut_line));
-    if (ut->ut_id)
-        strncpy (u.ut_id, ut->ut_id, sizeof (u.ut_id));
-    if (ut->ut_user)
-        strncpy (u.ut_user, ut->ut_user, sizeof (u.ut_user));
-    if (ut->ut_host)
-        strncpy (u.ut_host, ut->ut_host, sizeof (u.ut_host));
-    u.ut_tv.tv_sec = ut->ut_tv.tv_sec;
-    u.ut_tv.tv_usec = ut->ut_tv.tv_usec;
-
-    updwtmp (wtmp_file, &u);
-}
-
 #if HAVE_LIBAUDIT
 static void
 audit_event (int type, const gchar *username, uid_t uid, const gchar *remote_host_name, const gchar *tty, gboolean success)
@@ -364,7 +344,6 @@ session_child_run (int argc, char **argv)
             ut.ut_tv.tv_sec = tv.tv_sec;
             ut.ut_tv.tv_usec = tv.tv_usec;
 
-            updwtmpx ("/var/log/btmp", &ut);
 
 #if HAVE_LIBAUDIT
             audit_event (AUDIT_USER_LOGIN, username, -1, remote_host_name, tty, FALSE);
@@ -394,7 +373,7 @@ session_child_run (int argc, char **argv)
         else
         {
             /* Set POSIX variables */
-            pam_putenv (pam_handle, "PATH=/usr/local/bin:/usr/bin:/bin");
+            pam_putenv (pam_handle, "PATH=/sbin:/bin:/usr/sbin:/usr/bin:/usr/local/sbin:/usr/local/bin");
             pam_putenv (pam_handle, g_strdup_printf ("USER=%s", username));
             pam_putenv (pam_handle, g_strdup_printf ("LOGNAME=%s", username));
             pam_putenv (pam_handle, g_strdup_printf ("HOME=%s", user_get_home_directory (user)));
@@ -636,7 +615,29 @@ session_child_run (int argc, char **argv)
         /* Make this process its own session */
         if (setsid () < 0)
             _exit (errno);
-
+#if HAVE_SETUSERCONTEXT
+        /* Setup user context
+        * Reset the current environment to what is in the PAM context,
+        * then setusercontext will add to it as necessary as there is no
+        * option for setusercontext to add to a PAM context.
+        */
+        extern char **environ;
+        environ = pam_getenvlist (pam_handle);
+        struct passwd* pwd = getpwnam (username);
+        if (pwd) {
+            if (setusercontext (NULL, pwd, pwd->pw_uid, LOGIN_SETALL) < 0) {
+                int _errno = errno;
+                fprintf(stderr, "setusercontext for \"%s\" (%d) failed: %s\n",
+                    username, user_get_uid (user), strerror (errno));
+                _exit (_errno);
+            }
+            endpwent();
+        } else {
+            fprintf (stderr, "getpwname for \"%s\" failed: %s\n",
+                username, strerror (errno));
+            _exit (ENOENT);
+        }
+#else
         /* Change to this user */
         if (getuid () == 0)
         {
@@ -646,6 +647,7 @@ session_child_run (int argc, char **argv)
             if (setuid (uid) != 0)
                 _exit (errno);
         }
+#endif
 
         /* Change working directory */
         /* NOTE: This must be done after the permissions are changed because NFS filesystems can
@@ -668,7 +670,13 @@ session_child_run (int argc, char **argv)
         signal (SIGPIPE, SIG_DFL);
 
         /* Run the command */
-        execve (command_argv[0], command_argv, pam_getenvlist (pam_handle));
+        execve (command_argv[0], command_argv,
+#if HAVE_SETUSERCONTEXT
+            environ
+#else
+            pam_getenvlist (pam_handle)
+#endif
+        );
         _exit (EXIT_FAILURE);
     }
 
@@ -709,7 +717,6 @@ session_child_run (int argc, char **argv)
             if (!pututxline (&ut))
                 g_printerr ("Failed to write utmpx: %s\n", strerror (errno));
             endutxent ();
-            updwtmpx ("/var/log/wtmp", &ut);
 
 #if HAVE_LIBAUDIT
             audit_event (AUDIT_USER_LOGIN, username, uid, remote_host_name, tty, TRUE);
@@ -750,7 +757,6 @@ session_child_run (int argc, char **argv)
             if (!pututxline (&ut))
                 g_printerr ("Failed to write utmpx: %s\n", strerror (errno));
             endutxent ();
-            updwtmpx ("/var/log/wtmp", &ut);
 
 #if HAVE_LIBAUDIT
             audit_event (AUDIT_USER_LOGOUT, username, uid, remote_host_name, tty, TRUE);
