--- lib/common/readPNG.c.orig	1998-11-16 23:56:19.000000000 +0100
+++ lib/common/readPNG.c	2012-05-26 14:16:45.000000000 +0200
@@ -184,9 +184,11 @@
 	int i, idx, npass;
 	int width, height, color_type;
 	int ncolors, max_colors;
-	float gamma, fg_gamma;
+	float gamma;
+	double fg_gamma;
 	Boolean has_alpha = False, has_cmap = False, do_gamma = True;
 	png_bytep *row_ptrs;
+	png_colorp palette;
 	char msg[128];
 	static XmHTMLRawImageData *img_data;
 
@@ -265,17 +267,18 @@
 	ResetRawImage(img_data);
 
 	/* save width & height */
-	width  = img_data->width  = info_ptr->width;
-	height = img_data->height = info_ptr->height;
+	width  = img_data->width  = png_get_image_width(png_ptr, info_ptr);
+	height = img_data->height = png_get_image_height(png_ptr, info_ptr);
 
 	/* image depth */
-	ib->depth = info_ptr->bit_depth;
+	ib->depth = png_get_bit_depth(png_ptr, info_ptr);
 
 	/* no of colors */
-	ncolors = img_data->cmapsize = info_ptr->num_palette;
+	png_get_PLTE(png_ptr, info_ptr, &palette, &ncolors);
+	img_data->cmapsize = ncolors;
 
 	/* type of image */
-	color_type = info_ptr->color_type;
+	color_type = png_get_color_type(png_ptr, info_ptr);
 
 	/*
 	* The fun stuff. This is based on readPNG by Greg Roelofs as found
@@ -306,7 +309,7 @@
 			* Actual image creation is postponed until the image is
 			* needed.
 			*/
-			if(info_ptr->valid & PNG_INFO_tRNS)
+			if(png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
 			{
 				_XmHTMLDebug(15, ("readPNG.c: tRNS chunk present\n"));
 				png_set_expand(png_ptr);
@@ -319,9 +322,9 @@
 				AllocRawImageCmap(img_data, ncolors);
 				for(i = 0; i < ncolors; i++)
 				{
-					GETR(img_data->cmap[i]) = info_ptr->palette[i].red;
-					GETG(img_data->cmap[i]) = info_ptr->palette[i].green;
-					GETB(img_data->cmap[i]) = info_ptr->palette[i].blue;
+					GETR(img_data->cmap[i]) = palette[i].red;
+					GETG(img_data->cmap[i]) = palette[i].green;
+					GETB(img_data->cmap[i]) = palette[i].blue;
 				}
 				has_cmap = True;
 				data = (Byte*)malloc(width*height*sizeof(Byte));
@@ -355,7 +358,7 @@
 			* grayscale with transparency is expanded to RGB with alpha
 			* channel.
 			*/
-			if(info_ptr->valid & PNG_INFO_tRNS)
+			if(png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
 			{
 				_XmHTMLDebug(15, ("readPNG.c: tRNS chunk present\n"));
 				png_set_gray_to_rgb(png_ptr);
@@ -434,7 +437,7 @@
 			break;
 		default:
 			sprintf(msg, "bad PNG image: unknown color type (%d)",
-				info_ptr->color_type);
+				png_get_color_type(png_ptr, info_ptr));
 			my_png_error(png_ptr, msg);
 			break;
 	}
@@ -444,16 +447,18 @@
 	* Doing that for alpha channel images would change the colortype of the
 	* current image, leading to weird results.
 	*/
-	if(!has_alpha && info_ptr->valid & PNG_INFO_bKGD)
+	if(!has_alpha && png_get_valid(png_ptr, info_ptr, PNG_INFO_bKGD))
 	{
-		png_set_background(png_ptr, &(info_ptr->background),
+		png_color_16p background;
+		png_get_bKGD(png_ptr, info_ptr, &background);
+		png_set_background(png_ptr, background,
 			PNG_BACKGROUND_GAMMA_FILE, 1, 1.0);
-		img_data->bg = info_ptr->background.index;
+		img_data->bg = background->index;
 	}
 
 	/* handle gamma correction */
-	if(info_ptr->valid & PNG_INFO_gAMA)
-		fg_gamma = info_ptr->gamma;
+	if(png_get_valid(png_ptr, info_ptr, PNG_INFO_gAMA))
+		png_get_gAMA(png_ptr, info_ptr, &fg_gamma);
 	else
 		fg_gamma = 0.45;
 
@@ -464,20 +469,20 @@
 	/* dithering gets handled by caller */
 
 	/* one byte per pixel */
-	if(info_ptr->bit_depth < 8)
+	if(png_get_bit_depth(png_ptr, info_ptr) < 8)
 		png_set_packing(png_ptr);
 
 	/* no tRNS chunk handling, we've expanded it to an alpha channel. */
 
 	/* handle interlacing */
-	if(info_ptr->interlace_type)
+	if(png_get_interlace_type(png_ptr, info_ptr))
 		npass = png_set_interlace_handling(png_ptr);
 
 	/* and now update everything */
 	png_read_update_info(png_ptr, info_ptr);
 
 	/* has possibly changed if we have promoted GrayScale or tRNS chunks */
-	color_type = info_ptr->color_type;
+	color_type = png_get_color_type(png_ptr, info_ptr);
 
 	/* new color_type? */
 	if(color_type == PNG_COLOR_TYPE_RGB_ALPHA)
@@ -497,10 +502,10 @@
 		* will call doAlphaChannel to do the actual image creation. 
 		*/
 		row_ptrs = (png_bytep*)malloc(height*sizeof(png_bytep));
-		png_data = (png_bytep)malloc(height*info_ptr->rowbytes);
+		png_data = (png_bytep)malloc(height*png_get_rowbytes(png_ptr, info_ptr));
 
 		for(i = 0; i < height; i++)
-			row_ptrs[i] = (png_bytep)png_data + i*info_ptr->rowbytes;
+			row_ptrs[i] = (png_bytep)png_data + i*png_get_rowbytes(png_ptr, info_ptr);
 
 		/* read it */
 		png_read_image(png_ptr, row_ptrs);
@@ -529,7 +534,7 @@
 	row_ptrs = (png_bytep*)malloc(height*sizeof(png_bytep));
 
 	for(i = 0; i < height; ++i)
-		row_ptrs[i] = (png_bytep)data + i*info_ptr->rowbytes;
+		row_ptrs[i] = (png_bytep)data + i*png_get_rowbytes(png_ptr, info_ptr);
 
 	/* read it */
 	png_read_image(png_ptr, row_ptrs);
