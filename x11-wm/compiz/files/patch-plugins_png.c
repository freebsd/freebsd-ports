
--- plugins/png.c.orig	2010-04-01 13:17:02.000000000 +0300
+++ plugins/png.c	2010-04-01 13:17:34.000000000 +0300
@@ -167,7 +167,7 @@
     Bool	  status;
 
     sig_bytes = fread (png_sig, 1, PNG_SIG_SIZE, file);
-    if (png_check_sig (png_sig, sig_bytes) == 0)
+    if (!png_sig_cmp (png_sig, 1, sig_bytes) == 0)
 	return FALSE;
 
     png = png_create_read_struct (PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
@@ -218,7 +218,7 @@
     Bool		status;
 
     memcpy (png_sig, buffer, PNG_SIG_SIZE);
-    if (png_check_sig (png_sig, PNG_SIG_SIZE) == 0)
+    if (!png_sig_cmp (png_sig, 1, PNG_SIG_SIZE) == 0)
 	return FALSE;
 
     png = png_create_read_struct (PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);


