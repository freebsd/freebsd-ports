diff --git src/ImUtil.c src/ImUtil.c
index 83fd030..9e667bb 100644
--- src/ImUtil.c
+++ src/ImUtil.c
@@ -327,12 +327,13 @@ XImage *XCreateImage (dpy, visual, depth
 {
 	register XImage *image;
 	int bits_per_pixel = 1;
+	int min_bytes_per_line;
 
 	if (depth == 0 || depth > 32 ||
 	    (format != XYBitmap && format != XYPixmap && format != ZPixmap) ||
 	    (format == XYBitmap && depth != 1) ||
 	    (xpad != 8 && xpad != 16 && xpad != 32) ||
-	    offset < 0 || image_bytes_per_line < 0)
+	    offset < 0)
 	    return (XImage *) NULL;
 	if ((image = (XImage *) Xcalloc(1, (unsigned) sizeof(XImage))) == NULL)
 	    return (XImage *) NULL;
@@ -363,16 +364,21 @@ XImage *XCreateImage (dpy, visual, depth
 	/*
 	 * compute per line accelerator.
 	 */
-	if (image_bytes_per_line == 0)
 	{
 	if (format == ZPixmap)
-	    image->bytes_per_line = 
+	    min_bytes_per_line = 
 	       ROUNDUP((bits_per_pixel * width), image->bitmap_pad);
 	else
-	    image->bytes_per_line =
+	    min_bytes_per_line =
 	        ROUNDUP((width + offset), image->bitmap_pad);
 	}
-	else image->bytes_per_line = image_bytes_per_line;
+	if (image_bytes_per_line == 0) {
+	    image->bytes_per_line = min_bytes_per_line;
+	} else if (image_bytes_per_line < min_bytes_per_line) {
+	    return 0;
+	} else {
+	    image->bytes_per_line = image_bytes_per_line;
+	}
 
 	image->bits_per_pixel = bits_per_pixel;
 	image->obdata = NULL;
@@ -384,7 +390,11 @@ XImage *XCreateImage (dpy, visual, depth
 Status XInitImage (image)
     XImage *image;
 {
+	int min_bytes_per_line;
+
 	if (image->depth == 0 || image->depth > 32 ||
+	    image->bits_per_pixel > 32 || image->bitmap_unit > 32 ||
+	    image->bits_per_pixel < 0 || image->bitmap_unit < 0 ||
 	    (image->format != XYBitmap &&
 	     image->format != XYPixmap &&
 	     image->format != ZPixmap) ||
@@ -392,21 +402,24 @@ Status XInitImage (image)
 	    (image->bitmap_pad != 8 &&
 	     image->bitmap_pad != 16 &&
 	     image->bitmap_pad != 32) ||
-	    image->xoffset < 0 || image->bytes_per_line < 0)
+	    image->xoffset < 0)
 	    return 0;
 
 	/*
 	 * compute per line accelerator.
 	 */
-	if (image->bytes_per_line == 0)
-	{
 	if (image->format == ZPixmap)
-	    image->bytes_per_line = 
+	    min_bytes_per_line = 
 	       ROUNDUP((image->bits_per_pixel * image->width),
 		       image->bitmap_pad);
 	else
-	    image->bytes_per_line =
+	    min_bytes_per_line =
 	        ROUNDUP((image->width + image->xoffset), image->bitmap_pad);
+
+	if (image->bytes_per_line == 0) {
+	    image->bytes_per_line = min_bytes_per_line;
+	} else if (image->bytes_per_line < min_bytes_per_line) {
+	    return 0;
 	}
 
 	_XInitImageFuncPtrs (image);
