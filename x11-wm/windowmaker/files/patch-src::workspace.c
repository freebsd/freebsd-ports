--- src/workspace.c.orig	Fri Oct 15 06:14:43 2004
+++ src/workspace.c	Sun Oct 24 22:32:02 2004
@@ -738,16 +738,20 @@
 vdMouseMoveDesktop(XEvent *event, WMPoint direction)
 {
     static int lock = False;
-    if (lock) return;
-    lock = True;
 
     Bool done = False;
     Bool moved = True;
-    WScreen *scr = wScreenForRootWindow(event->xcrossing.root);
-    WMPoint old_pos = wmkpoint(event->xcrossing.x_root, event->xcrossing.y_root);
+    WScreen *scr;
+    WMPoint old_pos;
     WMPoint step;
     int x, y;
     int resisted = 0;
+
+    if (lock) return;
+    lock = True;
+
+    scr = wScreenForRootWindow(event->xcrossing.root);
+    old_pos = wmkpoint(event->xcrossing.x_root, event->xcrossing.y_root);
 
     if (XGrabPointer(dpy, event->xcrossing.window, False,
                      PointerMotionMask, GrabModeAsync, GrabModeAsync,
