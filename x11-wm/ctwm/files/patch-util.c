--- util.c.orig	2012-01-08 16:51:48.245308175 -0600
+++ util.c	2012-01-08 16:51:52.168309618 -0600
@@ -3941,7 +3941,7 @@
 #ifdef JPEG
 
 unsigned short int *buffer_16bpp;
-long *buffer_32bpp;
+uint32_t *buffer_32bpp;
 
 static void convert_for_16 (int w, int x, int y, int r, int g, int b) {
   buffer_16bpp [y * w + x] = ((r >> 3) << 11) + ((g >> 2) << 5) + (b >> 3);
