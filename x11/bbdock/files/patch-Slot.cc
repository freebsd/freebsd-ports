--- src/Slot.cc.orig	2011-03-29 19:48:36 UTC
+++ src/Slot.cc
@@ -420,6 +420,8 @@ const bool Slot::hasFocus()
  */
 void Slot::loadIcon()
 {
+	png_bytep *rowPointers;
+
 	destroyIcon();
 	width = height = 0;
 
@@ -446,27 +448,29 @@ void Slot::loadIcon()
 			PNG_TRANSFORM_BGR,
 			0 );
 
-		if( !(info->valid & PNG_INFO_IDAT) ||
-			!(normalicon = new int[info->width*info->height]) )
+		width = png_get_image_width( png, info );
+		height = png_get_image_height( png, info );
+
+		if( !png_get_valid( png, info, PNG_INFO_IDAT ) ||
+			!(normalicon = new int[width*height]) )
 			throw 0;
 
-		for( int y = 0, *src, *dest = normalicon; 
-			y < info->height && (src = (int *) info->row_pointers[y]); 
-			y++, dest += info->width )
-			memcpy( dest, src, info->width<<2 );
+		rowPointers = png_get_rows( png, info );
 
-		width = info->width;
-		height = info->height;
+		for( int y = 0, *src, *dest = normalicon; 
+			y < height && (src = (int *) rowPointers[y]);
+			y++, dest += width )
+			memcpy( dest, src, width<<2 );
 
 		// convert grayscale image to rgb
-		if( info->color_type == PNG_COLOR_TYPE_GRAY_ALPHA )
-			for( int y = info->height, *line = normalicon;
-				--y; line += info->width )
+		if( png_get_color_type(png, info) == PNG_COLOR_TYPE_GRAY_ALPHA )
+			for( int y = height, *line = normalicon;
+				--y; line += width )
 			{
-				unsigned char *dest = (unsigned char *) line+(info->width<<2);
-				unsigned char *src = (unsigned char *) line+(info->width<<1);
+				unsigned char *dest = (unsigned char *) line+(width<<2);
+				unsigned char *src = (unsigned char *) line+(width<<1);
 
-				for( int x = info->width; --x; )
+				for( int x = width; --x; )
 				{
 					*(--dest) = *(--src);
 					*(--dest) = *(--src);
