--- lib/libxview/base/xv_error.c.orig	Sat Oct  4 16:03:54 2003
+++ lib/libxview/base/xv_error.c	Sat Oct  4 16:52:26 2003
@@ -11,17 +11,22 @@
  */
 
 #include <stdio.h>
+#include <sys/param.h>
 #include <xview/pkg_public.h>
 #include <X11/Xlib.h>
 #include <xview_private/i18n_impl.h>
 #include <xview_private/portable.h>
 
 /* Unix system error variables */
-extern int      sys_nerr;
+extern const int      sys_nerr;
+#if (defined(BSD) && (BSD >= 199306))
+extern const char *const sys_errlist[];
+#else
 extern char    *sys_errlist[];
+#endif
 extern int      errno;
 
-Xv_private_data char *xv_app_name;
+extern Xv_private_data char *xv_app_name;
 Xv_private int (*xv_error_proc) ();
 
 /*
