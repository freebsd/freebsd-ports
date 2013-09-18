--- gif.c.orig	Thu Jan 13 15:36:06 1994
+++ gif.c	Mon Oct 19 13:46:15 1998
@@ -56,6 +56,10 @@
 	int     disposal;
 } Gif89 = { -1, -1, -1, 0 };
 
+static        ReadColorMap();
+static        DoExtension();
+static        GetDataBlock();
+
 extern XImage* ReadImage();
 
 XImage *ReadGIF(dpy, fd, pNcolors, pColors)
@@ -456,7 +460,7 @@
 	return code;
 }
 
-static XImage*
+extern XImage*
 ReadImage(dpy, fd, len, height, cmap, interlace, ignore)
 Display *dpy;
 FILE    *fd;
