--- img/codec_ungif.c	2011-07-25 21:52:32.000000000 +0400
+++ img/codec_ungif.c	2012-06-08 22:18:32.767947342 +0400
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
