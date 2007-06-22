--- bg.c.orig	Tue Apr 24 15:45:43 2007
+++ bg.c	Wed Jun 20 17:02:10 2007
@@ -237,7 +237,7 @@
     win =  GDK_WINDOW_XWINDOW(widget->window); 
     if (!XGetGeometry(bg->dpy, win, &dummy, &x, &y, &width, &height, &border,
               &depth)) {
-        DBG2("XGetGeometry failed\n");
+        DBG("XGetGeometry failed\n");
         RET(NULL);
     }
     XTranslateCoordinates(bg->dpy, win, bg->xroot, 0, 0, &x, &y, &dummy);
