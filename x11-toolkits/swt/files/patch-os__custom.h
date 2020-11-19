--- os_custom.h.orig	2019-03-07 02:31:04 UTC
+++ os_custom.h
@@ -105,7 +105,7 @@ glong g_utf16_offset_to_utf8_offset(const gchar*, glon
 glong g_utf8_offset_to_utf16_offset(const gchar*, glong);
 
 // Cached JVM pointer: see bug 521487.
-JavaVM *cached_jvm;
+extern JavaVM *cached_jvm;
 
 #define SWT_TYPE_FIXED (swt_fixed_get_type ())
 #define SWT_FIXED(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SWT_TYPE_FIXED, SwtFixed))
