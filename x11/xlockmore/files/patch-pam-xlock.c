--- ../xlockmore-5.20.1.orig/xlock/xlock.c	Thu Oct 27 04:09:29 2005
+++ xlock/xlock.c	Mon Dec 12 14:56:05 2005
@@ -3316,7 +3316,14 @@
 #ifdef USE_VTLOCK
 	if (!vtlock)
 #endif
+#ifdef BAD_PAM
+		(void) seteuid(ruid);
+#else
 		(void) setuid(ruid);
+#endif
+// #ifdef BAD_PAM ... #endif above will be added to prevent xlock from
+// dropping privileges when using PAM modules, that needs root rights
+// (pam_unix e.g.)
 
 #if 0
 	/* synchronize -- so I am aware of errors immediately */
