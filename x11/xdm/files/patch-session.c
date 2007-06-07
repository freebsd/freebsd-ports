--- session.c.orig	Sun Jun  3 22:49:51 2007
+++ session.c	Sun Jun  3 22:56:06 2007
@@ -543,6 +543,7 @@
     pid_t	pid;
 #ifdef HAS_SETUSERCONTEXT
     struct passwd* pwd;
+    extern char **environ;
 #endif
 #ifdef USE_PAM
     pam_handle_t *pamh = thepamh ();
@@ -627,6 +628,7 @@
 	    return (0);
 	}
 #endif   /* QNX4 doesn't support multi-groups, no initgroups() */
+#endif /* !HAS_SETUSERCONTEXT */
 #ifdef USE_PAM
 	if (pamh) {
 	    long i;
@@ -647,6 +649,7 @@
 
 	}
 #endif
+#ifndef HAS_SETUSERCONTEXT
 	if (setuid(verify->uid) < 0) {
 	    LogError ("setuid %d (user \"%s\") failed, errno=%d\n",
 		     verify->uid, name, errno);
@@ -657,6 +660,8 @@
 	 * Set the user's credentials: uid, gid, groups,
 	 * environment variables, resource limits, and umask.
 	 */
+	/* destroy user environment before calling setusercontext */
+	environ = verify->userEnviron;
 	pwd = getpwnam(name);
 	if (pwd) {
 	    if (setusercontext(NULL, pwd, pwd->pw_uid, LOGIN_SETALL) < 0) {
@@ -664,6 +669,7 @@
 		    errno);
 		return (0);
 	    }
+	    verify->userEnviron = environ;
 	    endpwent();
 	} else {
 	    LogError ("getpwnam for \"%s\" failed, errno=%d\n", name, errno);
