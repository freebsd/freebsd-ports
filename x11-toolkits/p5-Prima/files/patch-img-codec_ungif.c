--- img/codec_ungif.c.orig	2016-09-05 09:17:09 UTC
+++ img/codec_ungif.c
@@ -9,6 +9,10 @@
 extern "C" {
 #endif
 
+#ifndef GIF_LIB_VERSION
+#define GIF_LIB_VERSION " Version 4.2, "
+#endif
+
 static char * gifext[] = { "gif", nil };
 static char * gifver[] = { "gif87a", "gif89a", nil };
 static int    gifbpp[] = { 
