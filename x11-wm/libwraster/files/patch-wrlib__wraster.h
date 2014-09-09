--- wrlib/wraster.h.orig	2014-09-09 16:49:44 UTC
+++ wrlib/wraster.h
@@ -61,7 +61,7 @@
  * mechanism and define an internal macro appropriately. Please note that the macro are not considered being
  * part of the public API.
  */
-#if __GNUC__ >= 3
+#if (__GNUC__ >= 4 && __GNUC_MINOR__ >= 5) || __has_extension(attribute_deprecated_with_message)
 #define __wrlib_deprecated(msg)  __attribute__ ((deprecated(msg)))
 #else
 #define __wrlib_deprecated(msg)
