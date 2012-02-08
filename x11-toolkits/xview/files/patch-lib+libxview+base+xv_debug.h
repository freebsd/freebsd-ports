--- lib/libxview/base/xv_debug.h.orig	2005-03-28 06:41:49.000000000 -0800
+++ lib/libxview/base/xv_debug.h	2012-02-02 16:34:28.232644833 -0800
@@ -11,9 +11,14 @@
 
 #ifndef FILE
 #if !defined(SVR4) && !defined(__linux__)
+#ifdef NULL
 #undef NULL
+#endif
 #endif /* SVR4 */
 #include <stdio.h>
+#ifndef NULL
+#define NULL 0
+#endif
 #endif /* FILE */
 #include <xview/pkg.h>		/* needed to get definition of Xv_private */
   /* 
