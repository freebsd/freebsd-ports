--- ./lib/libxview/base/xv_debug.h.orig	Tue Jun 29 07:14:44 1993
+++ ./lib/libxview/base/xv_debug.h	Sat Apr  1 18:25:23 2000
@@ -9,11 +9,16 @@
 #ifndef _xv_debug_h_already_included
 #define _xv_debug_h_already_included
 
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
 #include <xview/pkg.h>		/* needed to get definition of Xv_private */
   /* 
