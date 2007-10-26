--- src/display.c.orig	2007-04-02 21:32:01.000000000 +0200
+++ src/display.c	2007-10-25 22:26:36.000000000 +0200
@@ -178,6 +178,19 @@
                           FALSE, display_info->atoms) != 0);
 }
 
+static void
+myDisplayCreateTimestampWin (DisplayInfo *display_info)
+{
+    XSetWindowAttributes attributes;
+
+    attributes.event_mask = PropertyChangeMask;
+    attributes.override_redirect = TRUE;
+    display_info->timestamp_win = 
+        XCreateWindow (display_info->dpy, DefaultRootWindow (display_info->dpy),
+                       -100, -100, 10, 10, 0, 0, CopyFromParent, CopyFromParent,
+                       CWEventMask | CWOverrideRedirect, &attributes);
+}
+
 DisplayInfo *
 myDisplayInit (GdkDisplay *gdisplay)
 {
@@ -309,6 +322,8 @@
     display->resize_cursor[CORNER_COUNT + SIDE_BOTTOM] =
         XCreateFontCursor (display->dpy, XC_bottom_side);
 
+    myDisplayCreateTimestampWin (display);
+
     display->xfilter = NULL;
     display->screens = NULL;
     display->clients = NULL;
@@ -340,6 +355,8 @@
     display->move_cursor = None;
     XFreeCursor (display->dpy, display->root_cursor);
     display->root_cursor = None;
+    XDestroyWindow (display->dpy, display->timestamp_win);
+    display->timestamp_win = None;
 
     if (display->hostname)
     {
