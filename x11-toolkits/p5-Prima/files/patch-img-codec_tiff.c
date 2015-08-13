--- img/codec_tiff.c.orig	2008-10-29 12:15:32.000000000 +0100
+++ img/codec_tiff.c	2010-08-26 21:32:37.000000000 +0200
@@ -164,7 +164,7 @@
 static ImgCodecInfo codec_info = {
    "TIFF Bitmap",
    "www.libtiff.org",
-   TIFF_VERSION, TIFFLIB_VERSION,    /* version */
+   TIFF_VERSION_CLASSIC, TIFFLIB_VERSION,    /* version */
    tiffext,    /* extension */
    "Tagged Image File Format",  /* file type */
    "TIFF", /* short type */
