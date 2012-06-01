--- src/kernel/qpngio.cpp.orig	2007-02-02 15:01:15.000000000 +0100
+++ src/kernel/qpngio.cpp	2012-04-27 10:52:06.000000000 +0200
@@ -43,6 +43,7 @@
 #include "qiodevice.h"
 
 #include <png.h>
+#include <pngpriv.h>
 
 
 #ifdef Q_OS_TEMP
@@ -159,7 +160,7 @@
 		image.setColor( i, qRgba(c,c,c,0xff) );
 	    }
 	    if ( png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS) ) {
-		const int g = info_ptr->trans_values.gray;
+		const int g = info_ptr->trans_color.gray;
 		if (g < ncols) {
 		    image.setAlphaBuffer(TRUE);
 		    image.setColor(g, image.color(g) & RGB_MASK);
@@ -187,7 +188,7 @@
 		    info_ptr->palette[i].red,
 		    info_ptr->palette[i].green,
 		    info_ptr->palette[i].blue,
-		    info_ptr->trans[i]
+		    info_ptr->trans_alpha[i]
 		    )
 		);
 		i++;
@@ -284,7 +285,7 @@
 	return;
     }
 
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
 	iio->setStatus(-4);
 	return;
@@ -469,7 +470,7 @@
 	return FALSE;
     }
 
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	png_destroy_write_struct(&png_ptr, &info_ptr);
 	return FALSE;
     }
@@ -1030,7 +1031,7 @@
 	    return -1;
 	}
 
-	if (setjmp((png_ptr)->jmpbuf)) {
+	if (setjmp(png_jmpbuf((png_ptr)))) {
 	    png_destroy_read_struct(&png_ptr, &info_ptr, 0);
 	    image = 0;
 	    return -1;
@@ -1057,7 +1058,7 @@
 
     if ( !png_ptr ) return 0;
 
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	png_destroy_read_struct(&png_ptr, &info_ptr, 0);
 	image = 0;
 	state = MovieStart;
