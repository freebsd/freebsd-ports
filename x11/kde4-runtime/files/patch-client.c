--- ./kdm/backend/client.c.orig	Sun Mar 24 12:31:09 2002
+++ ./kdm/backend/client.c	Thu Apr 18 20:53:44 2002
@@ -52,6 +52,12 @@
 #ifdef K5AUTH
 # include <krb5/krb5.h>
 #endif
+#ifdef CSRG_BASED
+# ifdef HAS_SETUSERCONTEXT
+#  include <login_cap.h>
+#  define USE_LOGIN_CAP 1
+# endif
+#endif
 #ifdef USE_PAM
 # include <security/pam_appl.h>
 #elif defined(AIXV3) /* USE_PAM */
@@ -71,13 +77,6 @@
 #   include <kafs.h>
 #  endif
 # endif
-# ifdef CSRG_BASED
-#  include <sys/param.h>
-#  ifdef HAS_SETUSERCONTEXT
-#   include <login_cap.h>
-#   define USE_LOGIN_CAP 1
-#  endif
-# endif
 /* for nologin */
 # include <sys/types.h>
 # include <unistd.h>
@@ -867,12 +866,11 @@
     char	*msg;
     char	**theenv;
     extern char	**newenv; /* from libs.a, this is set up by setpenv */
-# else
-#  ifdef HAS_SETUSERCONTEXT
-    extern char	**environ;
-#  endif
 # endif
 #endif
+#ifdef HAS_SETUSERCONTEXT
+    extern char	**environ;
+#endif
     char	*failsafeArgv[2];
     struct verify_info	*verify;
     int		i, pid;
@@ -1004,10 +1002,11 @@
 
 #ifndef AIXV3
 
-# if !defined(HAS_SETUSERCONTEXT) || defined(USE_PAM)
+# ifndef HAS_SETUSERCONTEXT
 	if (!SetGid (name, verify->gid))
 	    exit (1);
-#  ifdef USE_PAM
+# endif
+# ifdef USE_PAM
 	pam_setcred(pamh, 0);
 	/* pass in environment variables set by libpam and modules it called */
 	pam_env = pam_getenvlist(pamh);
@@ -1015,7 +1014,8 @@
 	if (pam_env)
 	    for(; *pam_env; pam_env++)
 		verify->userEnviron = putEnv(*pam_env, verify->userEnviron);
-#  endif
+# endif
+# ifndef HAS_SETUSERCONTEXT
 #  if defined(BSD) && (BSD >= 199103)
 	if (setlogin(name) < 0)
 	{
@@ -1025,7 +1025,8 @@
 #  endif
 	if (!SetUid (name, verify->uid))
 	    exit (1);
-# else /* HAS_SETUSERCONTEXT && !USE_PAM */
+# else /* HAS_SETUSERCONTEXT */
+
 	/*
 	 * Destroy environment unless user has requested its preservation.
 	 * We need to do this before setusercontext() because that may
