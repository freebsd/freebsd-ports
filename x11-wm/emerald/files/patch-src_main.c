--- src/main.c.orig	2010-11-02 16:54:19.000000000 +0100
+++ src/main.c	2010-11-02 16:56:04.000000000 +0100
@@ -2457,7 +2457,7 @@
     gdk_error_trap_push();
 
     type = None;
-    result = XGetWindowProperty(gdk_display,
+    result = XGetWindowProperty(GDK_DISPLAY_XDISPLAY (gdk_display_get_default ()),
 				xwindow,
 				atom,
 				0, G_MAXLONG,
@@ -4246,10 +4246,10 @@
     WnckWindow *win = data;
 
     gdk_error_trap_push();
-    XSetTransientForHint(gdk_display,
+    XSetTransientForHint(GDK_DISPLAY_XDISPLAY (gdk_display_get_default ()),
 			 GDK_WINDOW_XID(dialog->window),
 			 wnck_window_get_xid(win));
-    XSync(gdk_display, FALSE);
+    XSync(GDK_DISPLAY_XDISPLAY (gdk_display_get_default ()), FALSE);
     gdk_error_trap_pop();
 }
 
@@ -4262,11 +4262,11 @@
     int format, result;
     char *retval;
 
-    atom = XInternAtom(gdk_display, "WM_CLIENT_MACHINE", FALSE);
+    atom = XInternAtom(GDK_DISPLAY_XDISPLAY (gdk_display_get_default ()), "WM_CLIENT_MACHINE", FALSE);
 
     gdk_error_trap_push();
 
-    result = XGetWindowProperty(gdk_display,
+    result = XGetWindowProperty(GDK_DISPLAY_XDISPLAY (gdk_display_get_default ()),
 				xwindow, atom,
 				0, G_MAXLONG,
 				FALSE, XA_STRING, &type, &format, &nitems,
@@ -4318,8 +4318,8 @@
     }
 
     gdk_error_trap_push();
-    XKillClient(gdk_display, wnck_window_get_xid(win));
-    XSync(gdk_display, FALSE);
+    XKillClient(GDK_DISPLAY_XDISPLAY (gdk_display_get_default ()), wnck_window_get_xid(win));
+    XSync(GDK_DISPLAY_XDISPLAY (gdk_display_get_default ()), FALSE);
     gdk_error_trap_pop();
 }
 
@@ -4739,7 +4739,7 @@
 
 static int update_shadow(frame_settings * fs)
 {
-    Display *xdisplay = gdk_display;
+    Display *xdisplay = GDK_DISPLAY_XDISPLAY (gdk_display_get_default ());
     XRenderPictFormat *format;
     GdkPixmap *pixmap;
     Picture src, dst, tmp;
