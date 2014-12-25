--- nucleo/image/encoding/PNGenc.cxx.orig	2008-06-05 12:52:33 UTC
+++ nucleo/image/encoding/PNGenc.cxx
@@ -35,7 +35,7 @@ namespace nucleo {
   static void
   png_memory_write_data(png_structp png_ptr,
 				    png_bytep data, png_size_t length) {
-    png_in_memory *pim = (png_in_memory*)png_ptr->io_ptr ;
+    png_in_memory *pim = (png_in_memory*)png_get_io_ptr(png_ptr);
     
     void *pdst = pim->data+pim->p ;
     // std::cerr << "PNG: writing " << length << " bytes from " << (void *)data << " to " << pdst << std::endl ;
@@ -130,7 +130,7 @@ namespace nucleo {
 
   static void
   png_memory_read_data(png_structp png_ptr, png_bytep data, png_size_t length) {
-    png_in_memory *pim = (png_in_memory*)png_ptr->io_ptr ;
+    png_in_memory *pim = (png_in_memory*)png_get_io_ptr(png_ptr);
     memmove(data, pim->data+pim->p, length) ;
     pim->p+=length ;
   }
@@ -170,7 +170,7 @@ namespace nucleo {
 			  &compression_type, &filter_type) ;
 
     if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
-	 png_set_gray_1_2_4_to_8(png_ptr);
+	 png_set_expand_gray_1_2_4_to_8(png_ptr);
 
     if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
 	 png_set_tRNS_to_alpha(png_ptr);
