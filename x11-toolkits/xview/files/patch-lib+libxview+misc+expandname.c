--- ./lib/libxview/misc/expandname.c.orig	Tue Jun 29 07:16:30 1993
+++ ./lib/libxview/misc/expandname.c	Sat Apr  1 18:25:25 2000
@@ -120,7 +120,9 @@ xv_expand_name(name)
     }
     (void) close(pivec[0]);
 #ifndef SVR4
+#if !(defined(BSD) && (BSD >= 199103))
     while (wait((union wait *) & status) != pid);
+#endif
 #else SVR4
     while (wait( & status) != pid);
 #endif SVR4
