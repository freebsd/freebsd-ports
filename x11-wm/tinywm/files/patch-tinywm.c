
$FreeBSD$

--- tinywm.c.orig
+++ tinywm.c
@@ -12,12 +12,15 @@
 
 int main()
 {
+    int xdiff, ydiff;
     Display * dpy = XOpenDisplay(0);
+    XWindowAttributes attr;
+    XButtonEvent start;
+    XEvent ev;
+    Window root = DefaultRootWindow(dpy);
 
     if(!dpy) return 1;
 
-    Window root = DefaultRootWindow(dpy);
-
     XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("F1")), Mod1Mask, root,
             True, GrabModeAsync, GrabModeAsync);
     XGrabButton(dpy, 1, Mod1Mask, root, True, ButtonPressMask, GrabModeAsync,
@@ -25,9 +28,6 @@
     XGrabButton(dpy, 3, Mod1Mask, root, True, ButtonPressMask, GrabModeAsync,
             GrabModeAsync, None, None);
 
-    XWindowAttributes attr;
-    XButtonEvent start;
-    XEvent ev;
     for(;;)
     {
         XNextEvent(dpy, &ev);
@@ -44,8 +44,8 @@
         else if(ev.type == MotionNotify)
         {
             while(XCheckTypedEvent(dpy, MotionNotify, &ev));
-            int xdiff = ev.xbutton.x_root - start.x_root;
-            int ydiff = ev.xbutton.y_root - start.y_root;
+            xdiff = ev.xbutton.x_root - start.x_root;
+            ydiff = ev.xbutton.y_root - start.y_root;
             XMoveResizeWindow(dpy, ev.xmotion.window,
                 attr.x + (start.button==1 ? xdiff : 0),
                 attr.y + (start.button==1 ? ydiff : 0),
