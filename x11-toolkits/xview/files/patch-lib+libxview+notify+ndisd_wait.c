--- lib/libxview/notify/ndisd_wait.c.orig	Tue Jun 29 00:17:59 1993
+++ lib/libxview/notify/ndisd_wait.c	Thu Oct 16 17:37:44 2003
@@ -16,17 +16,18 @@
 #include <xview_private/ntfy.h>
 #include <xview_private/ndis.h>
 #include <signal.h>
+#include <sys/param.h>
 
 /* ARGSUSED */
 extern          Notify_value
 notify_default_wait3(client, pid, status, rusage)
     Notify_client   client;
     int             pid;
-#ifndef SVR4
+#if !((BSD4_4) || defined(SVR4))
     union wait     *status;
-#else SVR4
+#else /* SVR4 */
     int *status;
-#endif SVR4
+#endif /* SVR4 */
     struct rusage  *rusage;
 {
     return (NOTIFY_IGNORED);
