--- lib/libxview/sel/seln_impl.h.orig	2005-03-28 06:41:13.000000000 -0800
+++ lib/libxview/sel/seln_impl.h	2012-02-03 09:22:34.447913971 -0800
@@ -11,10 +11,15 @@
 
 #include <errno.h>
 #ifndef FILE
-#if !defined(SVR4) && !defined(__linux__) && !defined(__CYGWIN__)
+#if !defined(SVR4) && !defined(__linux__) && !defined(__CYGWIN__) 
+#ifdef NULL
 #undef NULL
+#endif
 #endif /* SVR4 */
 #include <stdio.h>
+#ifndef NULL
+#define NULL 0
+#endif
 #endif /* FILE */
 #include <sys/time.h>
 #include <sys/types.h>
