--- wrlib/wraster.h.orig	2015-08-11 18:41:14 UTC
+++ wrlib/wraster.h
@@ -61,10 +61,14 @@
  * mechanism and define an internal macro appropriately. Please note that the macro are not considered being
  * part of the public API.
  */
-#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 5)
+#ifndef __has_feature
+#define	__has_feature(x)	0
+#endif
+#ifndef __has_extension
+#define	__has_extension	__has_feature
+#endif
+#if __has_extension(attribute_depreated_with_message)
 #define __wrlib_deprecated(msg)  __attribute__ ((deprecated(msg)))
-#elif __GNUC__ >= 3
-#define __wrlib_deprecated(msg)  __attribute__ ((deprecated))
 #else
 #define __wrlib_deprecated(msg)
 #endif
