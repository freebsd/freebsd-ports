--- ./lib/libxview/sel/seln_impl.h.orig	Tue Jun 29 07:15:25 1993
+++ ./lib/libxview/sel/seln_impl.h	Sat Apr  1 18:25:27 2000
@@ -9,12 +9,17 @@
  *	file for terms of the license.
  */
 
+#ifdef NULL
+#undef NULL
+#endif
 #include <errno.h>
 #ifndef FILE
 #ifndef SVR4
-#undef NULL
 #endif SVR4
 #include <stdio.h>
+#ifndef NULL
+#define NULL 0
+#endif
 #endif FILE
 #include <sys/time.h>
 #include <sys/types.h>
