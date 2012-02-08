--- lib/libxview/notify/sys_select.c.orig	2005-03-28 06:41:00.000000000 -0800
+++ lib/libxview/notify/sys_select.c	2012-02-03 08:22:42.752727013 -0800
@@ -15,11 +15,15 @@
  */
 
 #ifndef SVR4
+#ifdef __FreeBSD__
+#include <sys/syscall.h>
+#else
 #if !defined __linux__ && !defined __CYGWIN__
 #include <syscall.h>
 #else
 #include "linux_select.h"
 #endif
+#endif /* __FreeBSD__ */
 #else /* SVR4 */
 #include <values.h>
 #include <sys/time.h>
