--- src/wdm/session.c.orig	Sat Mar 26 22:57:04 2005
+++ src/wdm/session.c	Sun Mar 27 09:22:42 2005
@@ -533,6 +533,7 @@
     int	pid;
 #ifdef HAS_SETUSERCONTEXT
     struct passwd* pwd;
+    extern char **environ;
 #endif
 #ifdef USE_PAM 
     pam_handle_t *pamh = thepamh();
@@ -562,6 +563,7 @@
 	/* Do system-dependent login setup here */
 
 #ifndef AIXV3
+#ifndef HAS_SETUSERCONTEXT
 	if (setgid(verify->gid) < 0)
 	{
 	    WDMError("setgid %d (user \"%s\") failed, errno=%d\n",
@@ -609,6 +611,31 @@
 		     verify->uid, name, errno);
 	    return (0);
 	}
+#else /* HAS_SETUSERCONTEXT */
+	/*
+	 * Set the user's credentials: uid, gid, groups,
+	 * environment variables, resource limits, and umask.
+	 */
+        /* destroy user environment before calling setusercontext */
+	environ = verify->userEnviron;
+	pwd = getpwnam(name);
+	if (pwd)
+	{
+	    if (setusercontext(NULL, pwd, pwd->pw_uid, LOGIN_SETALL) < 0)
+	    {
+		WDMError("setusercontext for \"%s\" failed, errno=%d\n", name,
+		    errno);
+		return (0);
+	    }
+            verify->userEnviron = environ;    
+	    endpwent();
+	}
+	else
+	{
+	    WDMError("getpwnam for \"%s\" failed, errno=%d\n", name, errno);
+	    return (0);
+	}
+#endif /* HAS_SETUSERCONTEXT */
 #else /* AIXV3 */
 	/*
 	 * Set the user's credentials: uid, gid, groups,
