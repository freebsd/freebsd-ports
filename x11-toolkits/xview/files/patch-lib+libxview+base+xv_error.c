--- lib/libxview/base/xv_error.c.orig	2005-03-28 06:41:48.000000000 -0800
+++ lib/libxview/base/xv_error.c	2012-02-02 16:41:03.978724572 -0800
@@ -11,6 +11,7 @@
  */
 
 #include <stdio.h>
+#include <sys/param.h>
 #include <xview/pkg_public.h>
 #include <X11/Xlib.h>
 #include <xview_private/i18n_impl.h>
@@ -21,12 +22,15 @@
 #include <errno.h>
 #else
 /* Unix system error variables */
-extern int      sys_nerr;
+#if (defined(BSD) && (BSD >= 199306))
+extern const char *const sys_errlist[];
+#else
 extern char    *sys_errlist[];
+#endif
 extern int      errno;
 #endif
 
-#if !defined(__linux__) && !defined(__CYGWIN__)
+#if !defined(__linux__) && !defined(__CYGWIN__) && !defined(__FreeBSD__)
 /* Global already defined in xv_init.c */
 Xv_private_data char *xv_app_name;
 #else
