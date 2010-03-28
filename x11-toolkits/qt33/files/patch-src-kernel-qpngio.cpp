--- src/kernel/qpngio.cpp.orig	2007-02-02 15:01:15.000000000 +0100
+++ src/kernel/qpngio.cpp	2010-03-28 14:00:46.000000000 +0200
@@ -159,7 +159,7 @@
 		image.setColor( i, qRgba(c,c,c,0xff) );
 	    }
 	    if ( png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS) ) {
-		const int g = info_ptr->trans_values.gray;
+		const int g = info_ptr->trans_color.gray;
 		if (g < ncols) {
 		    image.setAlphaBuffer(TRUE);
 		    image.setColor(g, image.color(g) & RGB_MASK);
@@ -187,7 +187,7 @@
 		    info_ptr->palette[i].red,
 		    info_ptr->palette[i].green,
 		    info_ptr->palette[i].blue,
-		    info_ptr->trans[i]
+		    info_ptr->trans_alpha[i]
 		    )
 		);
 		i++;
