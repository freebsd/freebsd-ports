--- ./lib/libxview/notify/ndet_fcntl.c.orig	Tue Jun 29 07:18:03 1993
+++ ./lib/libxview/notify/ndet_fcntl.c	Sat Apr  1 18:25:25 2000
@@ -17,22 +17,39 @@ static char     sccsid[] = "@(#)ndet_fcn
 
 #include <xview_private/ntfy.h>
 #include <xview_private/ndet.h>
+#include <sys/param.h>
 #include <signal.h>
 #include <fcntl.h>
 #ifdef SVR4
 #include <sys/file.h>
 #endif SVR4
-
+#if (defined(BSD) && (BSD >= 199103))
+#include <stdarg.h>
+#endif
 extern int
 #ifdef SVR4
 xv_fcntl(fd, cmd, arg)
 #else
+#if (defined(BSD) && (BSD >= 199103))
+fcntl(int fd, int cmd, ...)
+#else
 fcntl(fd, cmd, arg)
+#endif
 #endif SVR4
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
 
     /* Set fd bit */
     FD_ZERO(&bit);
