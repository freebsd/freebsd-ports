--- src/hints.c.orig	2007-03-11 14:44:43.000000000 +0100
+++ src/hints.c	2007-10-25 22:26:36.000000000 +0200
@@ -1167,27 +1167,18 @@
     return setXAtomManagerOwner(display_info, display_info->atoms[atom_id], root, w);
 }
 
-
-static Bool
-checkPropEvent (Display *display, XEvent *xevent, XPointer arg)
+void
+updateXserverTime (DisplayInfo *display_info)
 {
-    DisplayInfo *display_info;
     ScreenInfo *screen_info;
+    char c = '\0';
 
-    display_info = (DisplayInfo *) arg;
-    g_return_val_if_fail (display_info, FALSE);
-
-    screen_info = myDisplayGetDefaultScreen (display_info);
-    g_return_val_if_fail (screen_info, FALSE);
+    g_return_if_fail (display_info);
 
-    if ((xevent->type == PropertyNotify) &&
-        (xevent->xproperty.window == screen_info->xfwm4_win) &&
-        (xevent->xproperty.atom == display_info->atoms[XFWM4_TIMESTAMP_PROP]))
-    {
-        return TRUE;
-    }
-
-    return FALSE;
+    XChangeProperty (display_info->dpy, display_info->timestamp_win,
+                     display_info->atoms[XFWM4_TIMESTAMP_PROP],
+                     display_info->atoms[XFWM4_TIMESTAMP_PROP],
+                     8, PropModeReplace, (unsigned char *) &c, 1);
 }
 
 Time
@@ -1196,7 +1187,6 @@
     ScreenInfo *screen_info;
     XEvent xevent;
     Time timestamp;
-    char c = '\0';
 
     g_return_val_if_fail (display_info, (Time) CurrentTime);
     timestamp = myDisplayGetCurrentTime (display_info);
@@ -1206,12 +1196,8 @@
         g_return_val_if_fail (screen_info,  (Time) CurrentTime);
 
         TRACE ("getXServerTime: Using X server roundtrip");
-        XChangeProperty (display_info->dpy, screen_info->xfwm4_win, 
-                         display_info->atoms[XFWM4_TIMESTAMP_PROP],
-                         display_info->atoms[XFWM4_TIMESTAMP_PROP],
-                         8, PropModeReplace, (unsigned char *) &c, 1);
-        XIfEvent (display_info->dpy, &xevent, checkPropEvent, (XPointer) display_info);
-
+        updateXserverTime (display_info);
+        XWindowEvent (display_info->dpy, display_info->timestamp_win, PropertyChangeMask, &xevent);
         timestamp = (Time) myDisplayUpdateCurrentTime (display_info, &xevent);
     }
 
