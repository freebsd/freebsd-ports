--- lib/libxview/misc/expandname.c.orig	2005-03-28 06:41:36.000000000 -0800
+++ lib/libxview/misc/expandname.c	2012-02-02 20:25:52.508626867 -0800
@@ -122,7 +122,9 @@
     }
     (void) close(pivec[0]);
 #ifndef SVR4
+#if !(defined(BSD) && (BSD >= 199103))
     while (wait((union wait *) & status) != pid);
+#endif
 #else /* SVR4 */
     while (wait( & status) != pid);
 #endif /* SVR4 */
