--- gtk/window-decorator/gtk-window-decorator.c.orig	2009-08-15 03:24:40.000000000 -0400
+++ gtk/window-decorator/gtk-window-decorator.c	2010-11-24 15:21:52.000000000 -0500
@@ -380,7 +380,7 @@ typedef struct _decor {
     guint	      button_states[BUTTON_NUM];
     GdkPixmap	      *pixmap;
     GdkPixmap	      *buffer_pixmap;
-    GdkGC	      *gc;
+    cairo_t           *cr;
     decor_layout_t    border_layout;
     decor_context_t   *context;
     decor_shadow_t    *shadow;
@@ -918,6 +918,17 @@ button_state_paint (cairo_t	  *cr,
 }
 
 static void
+copy_to_front_buffer (decor_t *d)
+{
+    if (!d->buffer_pixmap)
+	return;
+
+    cairo_set_operator (d->cr, CAIRO_OPERATOR_SOURCE);
+    gdk_cairo_set_source_pixmap (d->cr, d->buffer_pixmap, 0, 0);
+    cairo_paint (d->cr);
+}
+
+static void
 draw_window_decoration (decor_t *d)
 {
     cairo_t       *cr;
@@ -1298,16 +1309,7 @@ draw_window_decoration (decor_t *d)
 
     cairo_destroy (cr);
 
-    if (d->buffer_pixmap)
-	gdk_draw_drawable  (d->pixmap,
-			    d->gc,
-			    d->buffer_pixmap,
-			    0,
-			    0,
-			    0,
-			    0,
-			    d->width,
-			    d->height);
+    copy_to_front_buffer (d);
 
     if (d->prop_xid)
     {
@@ -2103,16 +2105,7 @@ meta_draw_window_decoration (decor_t *d)
 	XRenderFreePicture (xdisplay, src);
     }
 
-    if (d->buffer_pixmap)
-	gdk_draw_drawable  (d->pixmap,
-			    d->gc,
-			    d->buffer_pixmap,
-			    0,
-			    0,
-			    0,
-			    0,
-			    d->width,
-			    d->height);
+    copy_to_front_buffer (d);
 
     if (d->prop_xid)
     {
@@ -2361,18 +2354,9 @@ draw_switcher_background (decor_t *d)
 				      alpha);
 
     cairo_stroke (cr);
-
     cairo_destroy (cr);
 
-    gdk_draw_drawable (d->pixmap,
-		       d->gc,
-		       d->buffer_pixmap,
-		       0,
-		       0,
-		       0,
-		       0,
-		       d->width,
-		       d->height);
+    copy_to_front_buffer (d);
 
     pixel = ((((a * style->bg[GTK_STATE_NORMAL].blue ) >> 24) & 0x0000ff) |
 	     (((a * style->bg[GTK_STATE_NORMAL].green) >> 16) & 0x00ff00) |
@@ -2439,15 +2423,7 @@ draw_switcher_foreground (decor_t *d)
 
     cairo_destroy (cr);
 
-    gdk_draw_drawable  (d->pixmap,
-			d->gc,
-			d->buffer_pixmap,
-			0,
-			0,
-			0,
-			0,
-			d->width,
-			d->height);
+    copy_to_front_buffer (d);
 }
 
 static void
@@ -2671,7 +2647,7 @@ get_window_prop (Window xwindow,
     gdk_error_trap_push ();
 
     type = None;
-    result = XGetWindowProperty (gdk_display,
+    result = XGetWindowProperty (GDK_DISPLAY_XDISPLAY (gdk_display_get_default ()),
 				 xwindow,
 				 atom,
 				 0, G_MAXLONG,
@@ -3512,15 +3488,15 @@ update_window_decoration_size (WnckWindo
     if (d->buffer_pixmap)
 	g_object_unref (G_OBJECT (d->buffer_pixmap));
 
-    if (d->gc)
-	g_object_unref (G_OBJECT (d->gc));
-
     if (d->picture)
 	XRenderFreePicture (xdisplay, d->picture);
 
+    if (d->cr)
+	cairo_destroy (d->cr);
+
     d->pixmap	     = pixmap;
     d->buffer_pixmap = buffer_pixmap;
-    d->gc	     = gdk_gc_new (pixmap);
+    d->cr            = gdk_cairo_create (pixmap);
 
     d->picture = picture;
 
@@ -3642,6 +3618,7 @@ update_switcher_window (WnckWindow *win,
     {
 	g_object_ref (G_OBJECT (switcher_pixmap));
 	d->pixmap = switcher_pixmap;
+	d->cr = gdk_cairo_create (switcher_pixmap);
     }
 
     if (!d->buffer_pixmap && switcher_buffer_pixmap)
@@ -3729,9 +3706,6 @@ update_switcher_window (WnckWindow *win,
 
     if (width == d->width && height == d->height)
     {
-	if (!d->gc)
-	    d->gc = gdk_gc_new (d->pixmap);
-
 	if (!d->picture)
 	    d->picture =
 		XRenderCreatePicture (xdisplay,
@@ -3765,8 +3739,8 @@ update_switcher_window (WnckWindow *win,
     if (d->buffer_pixmap)
 	g_object_unref (G_OBJECT (d->buffer_pixmap));
 
-    if (d->gc)
-	g_object_unref (G_OBJECT (d->gc));
+    if (d->cr)
+	cairo_destroy (d->cr);
 
     if (d->picture)
 	XRenderFreePicture (xdisplay, d->picture);
@@ -3782,7 +3756,7 @@ update_switcher_window (WnckWindow *win,
 
     d->pixmap	     = pixmap;
     d->buffer_pixmap = buffer_pixmap;
-    d->gc	     = gdk_gc_new (pixmap);
+    d->cr            = gdk_cairo_create (pixmap);
 
     d->picture = XRenderCreatePicture (xdisplay, GDK_PIXMAP_XID (buffer_pixmap),
 				       xformat, 0, NULL);
@@ -3817,10 +3791,10 @@ remove_frame_window (WnckWindow *win)
 	d->buffer_pixmap = NULL;
     }
 
-    if (d->gc)
+    if (d->cr)
     {
-	g_object_unref (G_OBJECT (d->gc));
-	d->gc = NULL;
+	cairo_destroy (d->cr);
+	d->cr = NULL;
     }
 
     if (d->picture)
@@ -4233,7 +4207,7 @@ show_tooltip (const char *text)
 static void
 hide_tooltip (void)
 {
-    if (GTK_WIDGET_VISIBLE (tip_window))
+    if (gtk_widget_get_visible (tip_window))
 	g_get_current_time (&tooltip_last_popdown);
 
     gtk_widget_hide (tip_window);
@@ -4966,7 +4940,7 @@ force_quit_dialog_realize (GtkWidget *di
     WnckWindow *win = data;
 
     gdk_error_trap_push ();
-    XSetTransientForHint (gdk_display,
+    XSetTransientForHint (GDK_DISPLAY_XDISPLAY (gdk_display_get_default ()),
 			  GDK_WINDOW_XID (dialog->window),
 			  wnck_window_get_xid (win));
     gdk_display_sync (gdk_display_get_default ());
@@ -4982,11 +4956,11 @@ get_client_machine (Window xwindow)
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
@@ -5038,7 +5012,7 @@ kill_window (WnckWindow *win)
     }
 
     gdk_error_trap_push ();
-    XKillClient (gdk_display, wnck_window_get_xid (win));
+    XKillClient (GDK_DISPLAY_XDISPLAY (gdk_display_get_default ()), wnck_window_get_xid (win));
     gdk_display_sync (gdk_display_get_default ());
     gdk_error_trap_pop ();
 }
@@ -5623,7 +5597,7 @@ static int
 update_shadow (void)
 {
     decor_shadow_options_t opt;
-    Display		   *xdisplay = gdk_display;
+    Display		   *xdisplay = GDK_DISPLAY_XDISPLAY (gdk_display_get_default ());
     GdkDisplay		   *display = gdk_display_get_default ();
     GdkScreen		   *screen = gdk_display_get_default_screen (display);
 
