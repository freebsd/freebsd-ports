--- ./src/background.C.orig	2010-12-03 22:08:19.000000000 +0100
+++ ./src/background.C	2010-12-29 12:27:37.000000000 +0100
@@ -56,6 +56,10 @@
 #define TIMING_TEST_PRINT_RESULT(id) do {} while (0)
 #endif
 
+#if defined( __FreeBSD__)
+# include <sys/endian.h>
+#endif
+
 /*
  * Pixmap geometry string interpretation :
  * Each geometry string contains zero or one scale/position
@@ -1596,7 +1600,15 @@
   rgba low;
   rgba high;
   int i;
+#if defined(HAVE_SYS_BYTEORDER_H)
   int host_byte_order = byteorder.big_endian () ? MSBFirst : LSBFirst;
+#else
+# if _BYTE_ORDER == _LITTLE_ENDIAN
+  int host_byte_order = LSBFirst;
+# else
+  int host_byte_order = MSBFirst;
+# endif
+#endif
 
   if (visual->c_class != TrueColor || ximage->format != ZPixmap) return;
 
