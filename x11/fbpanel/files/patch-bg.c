--- bg.c~	Sat Dec 18 17:41:41 2004
+++ bg.c	Sat Dec 18 17:43:04 2004
@@ -196,7 +196,7 @@
     ENTER;
     win =  GDK_WINDOW_XWINDOW(widget->window); 
     if (!XGetGeometry(bg->dpy, win, &dummy, &x, &y, &width, &height, &border, &depth)) {
-        DBG2("XGetGeometry failed\n");
+        DBG("XGetGeometry failed\n");
         RET(NULL);
     }
     XTranslateCoordinates(bg->dpy, win, bg->xroot, 0, 0, &x, &y, &dummy);
