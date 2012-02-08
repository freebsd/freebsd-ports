--- lib/libxview/frame/frame_help.h.orig	2005-03-28 06:41:27.000000000 -0800
+++ lib/libxview/frame/frame_help.h	2012-02-02 17:27:52.211890239 -0800
@@ -19,9 +19,14 @@
 /* standard includes */
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
 #include <sys/time.h>
 #include <xview/notify.h>
