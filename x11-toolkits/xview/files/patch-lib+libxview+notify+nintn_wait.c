--- lib/libxview/notify/nintn_wait.c.orig	Thu Oct 16 17:47:39 2003
+++ lib/libxview/notify/nintn_wait.c	Thu Oct 16 17:49:13 2003
@@ -22,11 +22,11 @@
 notify_next_wait3_func(nclient, pid, status, rusage)
     Notify_client   nclient;
     int             pid;
-#ifndef SVR4
+#if !(defined(BSD4_4) || defined(SVR4))
     union wait     *status;
-#else SVR4
+#else /* SVR4 */
     int *status;
-#endif SVR4
+#endif /* SVR4 */
     struct rusage  *rusage;
 {
     Notify_func     func;
