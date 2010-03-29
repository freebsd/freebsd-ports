--- src/FbTk/ImagePNG.cc.orig	2004-09-20 16:04:11.000000000 +0200
+++ src/FbTk/ImagePNG.cc	2010-03-29 21:44:37.000000000 +0200
@@ -88,7 +88,7 @@
     // check header
     unsigned char tag[4];
     fread(tag, 1, 4, fp);
-    if (!png_check_sig(tag, 4)) {
+    if (png_sig_cmp(tag, 0, 4)) {
         fclose(fp);
         return 0;
     }
