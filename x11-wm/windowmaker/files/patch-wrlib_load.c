--- wrlib/load.c.orig	2004-10-12 20:21:31.000000000 +0200
+++ wrlib/load.c	2010-03-29 07:34:45.000000000 +0200
@@ -348,7 +348,7 @@
 
 #ifdef USE_PNG
     /* check for PNG */
-    if (png_check_sig(buffer, 8))
+    if (!png_sig_cmp(buffer, 0, 8))
         return IM_PNG;
 #endif
 
