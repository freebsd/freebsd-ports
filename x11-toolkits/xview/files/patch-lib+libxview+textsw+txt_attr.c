--- lib/libxview/textsw/txt_attr.c.orig	Sun Oct  5 16:38:50 2003
+++ lib/libxview/textsw/txt_attr.c	Sun Oct  5 16:39:55 2003
@@ -19,7 +19,8 @@
 #include <xview_private/primal.h>
 #include <xview_private/txt_impl.h>
 #include <xview_private/txt_18impl.h>
-#ifdef SVR4
+#include <sys/param.h>
+#if (defined(BSD4_4) || defined(SVR4))
 #include <dirent.h>
 #include <string.h>
 #else
