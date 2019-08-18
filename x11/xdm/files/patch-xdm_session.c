--- xdm/session.c.orig	2019-03-02 22:06:13 UTC
+++ xdm/session.c
@@ -594,6 +594,7 @@ StartClient (
     pid_t	pid;
 #ifdef HAVE_SETUSERCONTEXT
     struct passwd* pwd;
+    extern char **environ;
 #endif
 #ifdef USE_PAM
     pam_handle_t *pamh = thepamh ();
@@ -678,6 +679,8 @@ StartClient (
 	 * Set the user's credentials: uid, gid, groups,
 	 * environment variables, resource limits, and umask.
 	 */
+	/* destroy user environment before calling setusercontext */
+	environ = verify->userEnviron;
 	pwd = getpwnam(name);
 	if (pwd) {
 	    if (setusercontext(NULL, pwd, pwd->pw_uid, LOGIN_SETALL) < 0) {
@@ -685,6 +688,7 @@ StartClient (
 			  name, _SysErrorMsg (errno));
 		return (0);
 	    }
+	    verify->userEnviron = environ;
 	    endpwent();
 	} else {
 	    LogError ("getpwnam for \"%s\" failed: %s\n",
