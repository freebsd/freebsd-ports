--- lib/libxview/notify/ndet_fcntl.c.orig	2005-03-28 06:41:00.000000000 -0800
+++ lib/libxview/notify/ndet_fcntl.c	2012-02-02 20:54:21.876186252 -0800
@@ -17,12 +17,13 @@
 
 #include <xview_private/ntfy.h>
 #include <xview_private/ndet.h>
+#include <sys/param.h>
 #include <signal.h>
 #include <fcntl.h>
 #if defined SVR4 || __CYGWIN__
 #include <sys/file.h>
 #endif /* SVR4 */
-#ifdef __linux__
+#if defined(__linux__) || (defined(BSD) && (BSD >= 199103))
 #include <stdarg.h>
 #endif
 
@@ -31,12 +32,26 @@
 #if defined SVR4 || __CYGWIN__
 xv_fcntl(fd, cmd, arg)
 #else
+#if (defined(BSD) && (BSD >= 199103))
+fcntl(int fd, int cmd, ...)
+#else
 fcntl(fd, cmd, arg)
+#endif
 #endif /* SVR4 */
+#if !(defined(BSD) && (BSD >= 199103))
     int             fd, cmd, arg;
+#endif
 {
     fd_set          bit;
     int             res;
+
+#if (defined(BSD) && (BSD >= 199103))
+    int arg;
+    va_list valist;
+    va_start(valist, cmd);
+    arg = va_arg(valist, int);
+    va_end(valist);
+#endif
 #else /* __linux__ */
 /* fcntl() is declared using variable args in linux */
 fcntl(int fd, int cmd, ...) {
