--- lib/libxview/panel/panel_impl.h.orig	2005-03-28 06:40:39.000000000 -0800
+++ lib/libxview/panel/panel_impl.h	2012-02-03 09:20:21.855877273 -0800
@@ -11,9 +11,14 @@
 
 #ifndef FILE
 #if !defined(SVR4) && !defined(__linux__) && !defined(__CYGWIN__)
+#ifdef NULL
 #undef NULL
+#endif
 #endif /* SVR4 */
 #include <stdio.h>
+#ifndef NULL
+#define NULL 0
+#endif
 #endif /* FILE */
 #include <sys/types.h>
 #include <X11/Xlib.h>
