--- panel.c.orig	Sun Oct 31 11:44:16 2004
+++ panel.c	Sun Oct 31 11:44:41 2004
@@ -297,7 +297,7 @@
 	
       image = RCreateImageFromDrawable(ctx, panel, 0);
       RConvertImage(ctx, image, &shrinkPixmap);
-      RDestroyImage(image);
+      RReleaseImage(image);
 	
       XSetWindowBackgroundPixmap(dpy, panel, shrinkPixmap);
       XUnmapSubwindows(dpy, panel);
