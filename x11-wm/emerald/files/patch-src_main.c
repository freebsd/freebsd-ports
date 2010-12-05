--- src/main.c.orig	2009-10-13 20:56:23.000000000 -0400
+++ src/main.c	2010-11-24 15:34:35.000000000 -0500
@@ -27,8 +27,8 @@
 #include <emerald.h>
 #include <engine.h>
 
-#define BASE_PROP_SIZE 12
-#define QUAD_PROP_SIZE 9
+//#define BASE_PROP_SIZE 12
+//#define QUAD_PROP_SIZE 9
 
 #ifndef DECOR_INTERFACE_VERSION
 #define DECOR_INTERFACE_VERSION 0
@@ -2457,7 +2457,7 @@ static gboolean get_window_prop(Window x
     gdk_error_trap_push();
 
     type = None;
-    result = XGetWindowProperty(gdk_display,
+    result = XGetWindowProperty(GDK_DISPLAY_XDISPLAY (gdk_display_get_default ()),
 				xwindow,
 				atom,
 				0, G_MAXLONG,
@@ -3757,7 +3757,7 @@
 
 static void hide_tooltip(void)
 {
-    if (GTK_WIDGET_VISIBLE(tip_window))
+    if (gtk_widget_get_visible(tip_window))
 	g_get_current_time(&tooltip_last_popdown);
 
     gtk_widget_hide(tip_window);
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
 
@@ -4262,11 +4262,11 @@ static char *get_client_machine(Window x
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
@@ -4318,8 +4318,8 @@ static void kill_window(WnckWindow * win
     }
 
     gdk_error_trap_push();
-    XKillClient(gdk_display, wnck_window_get_xid(win));
-    XSync(gdk_display, FALSE);
+    XKillClient(GDK_DISPLAY_XDISPLAY (gdk_display_get_default ()), wnck_window_get_xid(win));
+    XSync(GDK_DISPLAY_XDISPLAY (gdk_display_get_default ()), FALSE);
     gdk_error_trap_pop();
 }
 
@@ -4739,7 +4739,7 @@ static XFixed *create_gaussian_kernel(do
 
 static int update_shadow(frame_settings * fs)
 {
-    Display *xdisplay = gdk_display;
+    Display *xdisplay = GDK_DISPLAY_XDISPLAY (gdk_display_get_default ());
     XRenderPictFormat *format;
     GdkPixmap *pixmap;
     Picture src, dst, tmp;
