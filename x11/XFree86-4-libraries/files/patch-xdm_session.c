--- programs/xdm/session.c.orig	Wed May 30 00:56:22 2001
+++ programs/xdm/session.c	Fri Sep 28 23:25:16 2001
@@ -541,6 +541,7 @@
     int	pid;
 #ifdef HAS_SETUSERCONTEXT
     struct passwd* pwd;
+    extern char **environ;
 #endif
 #ifdef USE_PAM 
     pam_handle_t *pamh = thepamh();
@@ -623,6 +624,8 @@
 	 * Set the user's credentials: uid, gid, groups,
 	 * environment variables, resource limits, and umask.
 	 */
+        /* destroy user environment before calling setusercontext */
+	environ = verify->userEnviron;
 	pwd = getpwnam(name);
 	if (pwd)
 	{
@@ -632,6 +635,7 @@
 		    errno);
 		return (0);
 	    }
+            verify->userEnviron = environ;    
 	    endpwent();
 	}
 	else
