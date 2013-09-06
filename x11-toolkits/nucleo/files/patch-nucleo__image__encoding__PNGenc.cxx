--- ./nucleo/image/encoding/PNGenc.cxx.orig	2008-06-05 14:52:33.000000000 +0200
+++ ./nucleo/image/encoding/PNGenc.cxx	2013-09-06 23:12:11.842483995 +0200
@@ -16,6 +16,7 @@
 #include <nucleo/image/encoding/PNGenc.H>
 
 #include <png.h>
+#include <pngpriv.h>
 
 namespace nucleo {
 
@@ -170,7 +171,7 @@
 			  &compression_type, &filter_type) ;
 
     if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
-	 png_set_gray_1_2_4_to_8(png_ptr);
+	 png_set_expand_gray_1_2_4_to_8(png_ptr);
 
     if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
 	 png_set_tRNS_to_alpha(png_ptr);
