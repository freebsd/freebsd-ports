--- fvwm-insitu/libs/PictureImageLoader.c.orig	2008-12-09 12:52:20 UTC
+++ fvwm-insitu/libs/PictureImageLoader.c
@@ -145,7 +145,7 @@ Bool PImageLoadPng(FIMAGE_CMD_ARGS)
 		return False;
 	}
 #if 0
-	if (setjmp(Fpng_ptr->jmpbuf))
+	if (setjmp(png_jmpbuf(Fpng_ptr)))
 	{
 		Fpng_destroy_read_struct(&Fpng_ptr, &Finfo_ptr, NULL);
 		fclose(f);
@@ -165,16 +165,16 @@ Bool PImageLoadPng(FIMAGE_CMD_ARGS)
 	{
 		Fpng_set_expand(Fpng_ptr);
 	}
-	if (Finfo_ptr->color_type == FPNG_COLOR_TYPE_RGB_ALPHA)
+	if (png_get_color_type(Fpng_ptr, Finfo_ptr) == FPNG_COLOR_TYPE_RGB_ALPHA)
 	{
 		hasa = 1;
 	}
-	if (Finfo_ptr->color_type == FPNG_COLOR_TYPE_GRAY_ALPHA)
+	if (png_get_color_type(Fpng_ptr, Finfo_ptr) == FPNG_COLOR_TYPE_GRAY_ALPHA)
 	{
 		hasa = 1;
 		hasg = 1;
 	}
-	if (Finfo_ptr->color_type == FPNG_COLOR_TYPE_GRAY)
+	if (png_get_color_type(Fpng_ptr, Finfo_ptr) == FPNG_COLOR_TYPE_GRAY)
 	{
 		hasg = 1;
 	}
