--- fvwm-insitu/libs/Fpng.h.orig	2005-06-17 14:44:35.000000000 +0200
+++ fvwm-insitu/libs/Fpng.h	2010-03-29 19:25:39.000000000 +0200
@@ -429,7 +429,7 @@
 #define FPNG_FILLER_AFTER PNG_FILLER_AFTER
 #define FPNG_INFO_tRNS PNG_INFO_tRNS
 
-#define Fpng_check_sig(a,b) png_check_sig(a,b)
+#define Fpng_check_sig(a,b) (!png_sig_cmp(a,0,b))
 #define Fpng_create_read_struct(a,b,c,d) png_create_read_struct(a,b,c,d)
 #define Fpng_create_info_struct(a) png_create_info_struct(a)
 #define Fpng_destroy_read_struct(a,b,c) png_destroy_read_struct(a,b,c)
@@ -444,7 +444,7 @@
 #define Fpng_set_packing(a) png_set_packing(a)
 #define Fpng_set_gray_to_rgb(a) png_set_gray_to_rgb(a)
 #define Fpng_get_bit_depth(a,b) png_get_bit_depth(a,b)
-#define Fpng_set_gray_1_2_4_to_8(a) png_set_gray_1_2_4_to_8(a)
+#define Fpng_set_gray_1_2_4_to_8(a) png_set_expand_gray_1_2_4_to_8(a)
 #define Fpng_get_valid(a,b,c) png_get_valid(a,b,c)
 #define Fpng_read_end(a,b) png_read_end(a,b)
 #define Fpng_set_interlace_handling(a) png_set_interlace_handling(a)
