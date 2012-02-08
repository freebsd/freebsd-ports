--- lib/libxview/notify/nintn_wait.c.orig	2005-03-28 06:41:00.000000000 -0800
+++ lib/libxview/notify/nintn_wait.c	2012-02-02 21:22:32.283495742 -0800
@@ -22,7 +22,7 @@
 notify_next_wait3_func(nclient, pid, status, rusage)
     Notify_client   nclient;
     int             pid;
-#if !defined SVR4 && !defined __CYGWIN__
+#if !defined SVR4 && !defined __CYGWIN__ && !defined BSD4_4
     union wait     *status;
 #else /* SVR4 */
     int *status;
