--- ./lib/libxview/panel/panel_impl.h.orig	Tue Jun 29 07:16:50 1993
+++ ./lib/libxview/panel/panel_impl.h	Sat Apr  1 18:25:27 2000
@@ -9,11 +9,16 @@
 #ifndef panel_impl_defined
 #define panel_impl_defined
 
+#ifdef NULL
+#undef NULL
+#endif
 #ifndef FILE
 #ifndef SVR4
-#undef NULL
 #endif SVR4
 #include <stdio.h>
+#ifndef NULL
+#define NULL 0
+#endif
 #endif FILE
 #include <sys/types.h>
 #include <X11/Xlib.h>
