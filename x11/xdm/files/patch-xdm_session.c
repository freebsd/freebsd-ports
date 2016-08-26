--- xdm/session.c.orig	2011-09-25 07:35:47 UTC
+++ xdm/session.c
@@ -575,6 +575,7 @@ StartClient (
     pid_t	pid;
 #ifdef HAVE_SETUSERCONTEXT
     struct passwd* pwd;
+    extern char **environ;
 #endif
 #ifdef USE_PAM
     pam_handle_t *pamh = thepamh ();
@@ -695,6 +696,8 @@ StartClient (
 	 * Set the user's credentials: uid, gid, groups,
 	 * environment variables, resource limits, and umask.
 	 */
+	/* destroy user environment before calling setusercontext */
+	environ = verify->userEnviron;
 	pwd = getpwnam(name);
 	if (pwd) {
 	    if (setusercontext(NULL, pwd, pwd->pw_uid, LOGIN_SETALL) < 0) {
@@ -702,6 +705,7 @@ StartClient (
 			  name, _SysErrorMsg (errno));
 		return (0);
 	    }
+	    verify->userEnviron = environ;
 	    endpwent();
 	} else {
 	    LogError ("getpwnam for \"%s\" failed: %s\n",
