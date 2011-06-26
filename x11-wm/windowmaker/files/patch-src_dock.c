--- src/dock.c.orig	2011-05-04 09:33:23.000000000 +0200
+++ src/dock.c	2011-05-04 09:33:47.000000000 +0200
@@ -3801,7 +3801,7 @@
 
 
     if (wPreferences.flags.noupdates)
-        return;
+        return False;
 
     if (XGrabPointer(dpy, icon->core->window, True, ButtonMotionMask
                      |ButtonReleaseMask|ButtonPressMask, GrabModeAsync,
