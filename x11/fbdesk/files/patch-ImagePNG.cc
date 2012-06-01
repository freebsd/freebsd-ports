--- src/FbTk/ImagePNG.cc.orig	2004-09-20 16:04:11.000000000 +0200
+++ src/FbTk/ImagePNG.cc	2012-05-06 09:59:07.000000000 +0200
@@ -28,6 +28,7 @@
 #include "PixmapWithMask.hh"
 
 #include <png.h>
+#include <pngpriv.h>
 #include <cstdio>
 #include <iostream>
 using namespace std;
@@ -88,7 +89,7 @@
     // check header
     unsigned char tag[4];
     fread(tag, 1, 4, fp);
-    if (!png_check_sig(tag, 4)) {
+    if (png_sig_cmp(tag, 0, 4)) {
         fclose(fp);
         return 0;
     }
@@ -102,7 +103,7 @@
         return 0;
     }
 
-    if (setjmp(png.png()->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png.png()))) {
         fclose(fp);
         return 0;
     }
