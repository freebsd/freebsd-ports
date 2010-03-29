--- ksplash/ksplashx/qpngio.cpp.orig	2008-01-05 00:55:38.000000000 +0100
+++ ksplash/ksplashx/qpngio.cpp	2010-03-29 07:49:55.000000000 +0200
@@ -151,7 +151,7 @@
 		image.setColor( i, qRgba(c,c,c,0xff) );
 	    }
 	    if ( png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS) ) {
-		const int g = info_ptr->trans_values.gray;
+		const int g = info_ptr->trans_color.gray;
 		if (g < ncols) {
 		    image.setAlphaBuffer(true);
 		    image.setColor(g, image.color(g) & RGB_MASK);
@@ -179,7 +179,7 @@
 		    info_ptr->palette[i].red,
 		    info_ptr->palette[i].green,
 		    info_ptr->palette[i].blue,
-		    info_ptr->trans[i]
+		    info_ptr->trans_alpha[i]
 		    )
 		);
 		i++;
@@ -307,9 +307,9 @@
 png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS)
     if (image.depth()==32 && png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS)) {
 	QRgb trans = 0xFF000000 | qRgb(
-	      (info_ptr->trans_values.red << 8 >> bit_depth)&0xff,
-	      (info_ptr->trans_values.green << 8 >> bit_depth)&0xff,
-	      (info_ptr->trans_values.blue << 8 >> bit_depth)&0xff);
+	      (info_ptr->trans_color.red << 8 >> bit_depth)&0xff,
+	      (info_ptr->trans_color.green << 8 >> bit_depth)&0xff,
+	      (info_ptr->trans_color.blue << 8 >> bit_depth)&0xff);
 	for (uint y=0; y<height; y++) {
 	    for (uint x=0; x<info_ptr->width; x++) {
 		if (((uint**)jt)[y][x] == trans) {
