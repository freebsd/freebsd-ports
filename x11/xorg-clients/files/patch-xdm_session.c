--- programs/xdm/session.c.orig	Thu Mar  4 09:48:55 2004
+++ programs/xdm/session.c	Wed Jun 16 16:59:46 2004
@@ -55,7 +55,6 @@
 #ifdef SECURE_RPC
 # include <rpc/rpc.h>
 # include <rpc/key_prot.h>
-extern int key_setnet(struct key_netstarg *arg);
 #endif
 #ifdef K5AUTH
 # include <krb5/krb5.h>
@@ -529,6 +528,7 @@
     int	pid;
 #ifdef HAS_SETUSERCONTEXT
     struct passwd* pwd;
+    extern char **environ;
 #endif
 #ifdef USE_PAM
     pam_handle_t *pamh = thepamh ();
@@ -610,6 +610,8 @@
 	 * Set the user's credentials: uid, gid, groups,
 	 * environment variables, resource limits, and umask.
 	 */
+        /* destroy user environment before calling setusercontext */
+	environ = verify->userEnviron;
 	pwd = getpwnam(name);
 	if (pwd) {
 	    if (setusercontext(NULL, pwd, pwd->pw_uid, LOGIN_SETALL) < 0) {
@@ -617,6 +619,7 @@
 		    errno);
 		return (0);
 	    }
+            verify->userEnviron = environ;    
 	    endpwent();
 	} else {
 	    LogError ("getpwnam for \"%s\" failed, errno=%d\n", name, errno);
