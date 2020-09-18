--- src/window.c.orig	2004-07-22 03:09:55 UTC
+++ src/window.c
@@ -898,7 +898,7 @@ make_pixmap (const char *name, int width, int height, 
 	    gdk_imlib_render (image, max (width, 22), max (height, 22));
 	    pixmap = gdk_imlib_move_image (image);
 	    mask   = gdk_imlib_move_mask (image);
-	    if (strchr (g_basename (path), '.')) /* don't cache x-of-day */
+	    if (strchr (g_path_get_basename (path), '.')) /* don't cache x-of-day */
 	       gdk_imlib_destroy_image (image);
 	    else
 	       gdk_imlib_kill_image (image);
@@ -1069,7 +1069,7 @@ save_config_file (GtkWidget *widget, gpointer ptr)
 	 WMReleasePropList (all_keys);
       }
 
-      if (WMWritePropListToFile (newwm, orig_wmaker_fname, YES))
+      if (WMWritePropListToFile (newwm, orig_wmaker_fname))
       {
 	 changed = NO;
 	 message (_("Window Maker config file '%s' saved."),
