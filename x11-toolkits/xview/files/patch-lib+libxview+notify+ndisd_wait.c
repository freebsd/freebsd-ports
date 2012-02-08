--- lib/libxview/notify/ndisd_wait.c.orig	2005-03-28 06:41:00.000000000 -0800
+++ lib/libxview/notify/ndisd_wait.c	2012-02-02 21:15:25.836613036 -0800
@@ -16,13 +16,14 @@
 #include <xview_private/ntfy.h>
 #include <xview_private/ndis.h>
 #include <signal.h>
+#include <sys/param.h>
 
 /* ARGSUSED */
 extern          Notify_value
 notify_default_wait3(client, pid, status, rusage)
     Notify_client   client;
     int             pid;
-#if !defined SVR4 && !defined __CYGWIN__
+#if !defined SVR4 && !defined __CYGWIN__ && !defined BSD4_4
     union wait     *status;
 #else /* SVR4 */
     int *status;
