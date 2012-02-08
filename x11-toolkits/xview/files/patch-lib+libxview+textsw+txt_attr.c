--- lib/libxview/textsw/txt_attr.c.orig	2005-03-28 06:40:33.000000000 -0800
+++ lib/libxview/textsw/txt_attr.c	2012-02-03 09:51:40.604742562 -0800
@@ -19,7 +19,7 @@
 #include <xview_private/primal.h>
 #include <xview_private/txt_impl.h>
 #include <xview_private/txt_18impl.h>
-#if defined SVR4 || defined __CYGWIN__
+#if defined SVR4 || defined __CYGWIN__ || defined(__FreeBSD__)
 #include <dirent.h>
 #include <string.h>
 #else
