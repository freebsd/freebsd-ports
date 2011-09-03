--- ../generic/tkImgGIF.c	2002-03-26 03:29:01.000000000 +0100
+++ ../generic/tkImgGIF.new.c	2007-10-04 20:40:09.000000000 +0200
@@ -960,7 +960,7 @@
 	/* If interlacing, the next ypos is not just +1 */
 	if (interlace) {
 	    ypos += interlaceStep[pass];
-	    while (ypos >= height) {
+	    while (ypos >= rows) {
 		pass++;
 		if (pass > 3) {
 		    return TCL_OK;
