--- img/codec_ungif.c.orig	2011-07-25 17:52:32 UTC
+++ img/codec_ungif.c
@@ -37,6 +37,10 @@
 extern "C" {
 #endif
 
+#ifndef GIF_LIB_VERSION
+#define GIF_LIB_VERSION " Version 4.2, "
+#endif
+
 static char * gifext[] = { "gif", nil };
 static char * gifver[] = { "gif87a", "gif89a", nil };
 static int    gifbpp[] = { 
