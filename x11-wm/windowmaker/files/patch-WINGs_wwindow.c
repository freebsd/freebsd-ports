--- WINGs/wwindow.c
+++ WINGs/wwindow.c
@@ -254,14 +254,14 @@
 setMiniwindow(WMWindow *win, RImage *image)
 {
     WMScreen *scr= win->view->screen;
-    CARD32 *data;
+    long *data;
     int x, y;
     int o;
 
     if (!image)
       return;
 
-    data = wmalloc((image->width * image->height + 2) * sizeof(CARD32));
+    data = wmalloc((image->width * image->height + 2) * sizeof(long));
 
     o= 0;
     data[o++] = image->width;
