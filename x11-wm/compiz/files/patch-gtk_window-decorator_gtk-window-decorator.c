--- gtk/window-decorator/gtk-window-decorator.c.orig	2009-08-15 09:24:40.000000000 +0200
+++ gtk/window-decorator/gtk-window-decorator.c	2010-10-29 12:56:37.000000000 +0200
@@ -2671,7 +2671,7 @@ get_window_prop (Window xwindow,
     gdk_error_trap_push ();
 
     type = None;
-    result = XGetWindowProperty (gdk_display,
+    result = XGetWindowProperty (GDK_DISPLAY_XDISPLAY (gdk_display_get_default ()),
 				 xwindow,
 				 atom,
 				 0, G_MAXLONG,
@@ -4233,7 +4233,7 @@ show_tooltip (const char *text)
 static void
 hide_tooltip (void)
 {
-    if (GTK_WIDGET_VISIBLE (tip_window))
+    if (gtk_widget_get_visible (tip_window))
 	g_get_current_time (&tooltip_last_popdown);
 
     gtk_widget_hide (tip_window);
@@ -4966,7 +4966,7 @@ force_quit_dialog_realize (GtkWidget *di
     WnckWindow *win = data;
 
     gdk_error_trap_push ();
-    XSetTransientForHint (gdk_display,
+    XSetTransientForHint (GDK_DISPLAY_XDISPLAY (gdk_display_get_default ()),
 			  GDK_WINDOW_XID (dialog->window),
 			  wnck_window_get_xid (win));
     gdk_display_sync (gdk_display_get_default ());
@@ -4982,11 +4982,11 @@ get_client_machine (Window xwindow)
     int    format, result;
     char   *retval;
 
-    atom = XInternAtom (gdk_display, "WM_CLIENT_MACHINE", FALSE);
+    atom = XInternAtom (GDK_DISPLAY_XDISPLAY (gdk_display_get_default ()), "WM_CLIENT_MACHINE", FALSE);
 
     gdk_error_trap_push ();
 
-    result = XGetWindowProperty (gdk_display,
+    result = XGetWindowProperty (GDK_DISPLAY_XDISPLAY (gdk_display_get_default ()),
 				 xwindow, atom,
 				 0, G_MAXLONG,
 				 FALSE, XA_STRING, &type, &format, &nitems,
@@ -5038,7 +5038,7 @@ kill_window (WnckWindow *win)
     }
 
     gdk_error_trap_push ();
-    XKillClient (gdk_display, wnck_window_get_xid (win));
+    XKillClient (GDK_DISPLAY_XDISPLAY (gdk_display_get_default ()), wnck_window_get_xid (win));
     gdk_display_sync (gdk_display_get_default ());
     gdk_error_trap_pop ();
 }
@@ -5623,7 +5623,7 @@ static int
 update_shadow (void)
 {
     decor_shadow_options_t opt;
-    Display		   *xdisplay = gdk_display;
+    Display		   *xdisplay = GDK_DISPLAY_XDISPLAY (gdk_display_get_default ());
     GdkDisplay		   *display = gdk_display_get_default ();
     GdkScreen		   *screen = gdk_display_get_default_screen (display);
 
