--- wrlib/wraster.h.orig	2014-08-30 21:29:09.000000000 +0900
+++ wrlib/wraster.h	2014-09-15 02:31:40.000000000 +0900
@@ -61,7 +61,13 @@
  * mechanism and define an internal macro appropriately. Please note that the macro are not considered being
  * part of the public API.
  */
-#if __GNUC__ >= 3
+#ifndef __has_feature
+#define	__has_feature(x) 0
+#endif
+#ifndef __has_extension
+#define	__has_extension __has_feature
+#endif
+#if __has_extension(attribute_deprecated_with_message)
 #define __wrlib_deprecated(msg)  __attribute__ ((deprecated(msg)))
 #else
 #define __wrlib_deprecated(msg)
