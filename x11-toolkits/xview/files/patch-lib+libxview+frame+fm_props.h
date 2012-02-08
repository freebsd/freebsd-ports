--- lib/libxview/frame/fm_props.h.orig	2005-03-28 06:41:27.000000000 -0800
+++ lib/libxview/frame/fm_props.h	2012-02-02 17:18:57.633679042 -0800
@@ -15,9 +15,14 @@
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
