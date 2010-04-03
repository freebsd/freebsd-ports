--- plugins/png.c.orig	2009-09-01 07:38:22.000000000 +0200
+++ plugins/png.c	2010-04-03 22:08:10.000000000 +0200
@@ -102,7 +102,7 @@
 
     /* expand gray bit depth if needed */
     if (color_type == PNG_COLOR_TYPE_GRAY && depth < 8)
-	png_set_gray_1_2_4_to_8 (png);
+	png_set_expand_gray_1_2_4_to_8 (png);
 
     /* transform transparency to alpha */
     if (png_get_valid(png, info, PNG_INFO_tRNS))
@@ -167,7 +167,7 @@
     Bool	  status;
 
     sig_bytes = fread (png_sig, 1, PNG_SIG_SIZE, file);
-    if (png_check_sig (png_sig, sig_bytes) == 0)
+    if (!png_sig_cmp (png_sig, 0, sig_bytes) == 0)
 	return FALSE;
 
     png = png_create_read_struct (PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
@@ -218,7 +218,7 @@
     Bool		status;
 
     memcpy (png_sig, buffer, PNG_SIG_SIZE);
-    if (png_check_sig (png_sig, PNG_SIG_SIZE) == 0)
+    if (!png_sig_cmp (png_sig, 0, PNG_SIG_SIZE) == 0)
 	return FALSE;
 
     png = png_create_read_struct (PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
