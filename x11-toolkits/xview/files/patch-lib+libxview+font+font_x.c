--- lib/libxview/font/font_x.c.orig	Sun Oct  5 12:16:24 2003
+++ lib/libxview/font/font_x.c	Sun Oct  5 12:18:03 2003
@@ -127,7 +127,7 @@
 	 */
 	*default_x = font->max_bounds.width;
 	*default_y = font->ascent + font->descent;
-	if (font->min_byte1 || font->max_byte1)
+	if (font->min_byte1)	/* mbuck@debian.org */
 	    ERROR;
 	*max_char = MIN(255, font->max_char_or_byte2);	/* pixfont compat */
 	*min_char = MIN(255, font->min_char_or_byte2);	/* pixfont compat */
