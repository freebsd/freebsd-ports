--- graphics.c.orig	Sun Oct 31 11:44:10 2004
+++ graphics.c	Sun Oct 31 11:44:54 2004
@@ -73,7 +73,7 @@
    img = RCloneImage(bottom);
    RCombineImages(img, top);
    setWindowImage(win, img);
-   RDestroyImage(img);
+   RReleaseImage(img);
 }
 
 void drawText(Window win, XFontStruct* font, int justification, int x, int y, 
