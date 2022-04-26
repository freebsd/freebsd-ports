--- src/icons.c.orig	2021-01-05 08:18:20 UTC
+++ src/icons.c
@@ -295,16 +295,26 @@ static void
 }
 
 static void
-get_pixmap_geometry (Display *dpy, Pixmap pixmap, guint *out_width, guint *out_height, guint *out_depth)
+get_pixmap_geometry (ScreenInfo *screen_info, Pixmap pixmap, guint *out_width, guint *out_height, guint *out_depth)
 {
     Window root;
     guint border_width;
     gint x, y;
     guint width, height;
     guint depth;
+    Status rc;
+    int result;
 
-    XGetGeometry (dpy, pixmap, &root, &x, &y, &width, &height, &border_width, &depth);
+    myDisplayErrorTrapPush (screen_info->display_info);
+    rc = XGetGeometry (myScreenGetXDisplay(screen_info), pixmap, &root,
+                       &x, &y, &width, &height, &border_width, &depth);
+    result = myDisplayErrorTrapPop (screen_info->display_info);
 
+    if ((rc != Success) || (result != Success))
+    {
+        return;
+    }
+
     if (out_width != NULL)
     {
         *out_width = width;
@@ -371,12 +381,12 @@ try_pixmap_and_mask (ScreenInfo *screen_info, Pixmap s
         return NULL;
     }
 
-    get_pixmap_geometry (myScreenGetXDisplay(screen_info), src_pixmap, &w, &h, &depth);
+    get_pixmap_geometry (screen_info, src_pixmap, &w, &h, &depth);
     surface = get_surface_from_pixmap (screen_info, src_pixmap, w, h, depth);
 
     if (surface && src_mask != None)
     {
-        get_pixmap_geometry (myScreenGetXDisplay(screen_info), src_mask, &w, &h, &depth);
+        get_pixmap_geometry (screen_info, src_mask, &w, &h, &depth);
         mask_surface = get_surface_from_pixmap (screen_info, src_mask, w, h, depth);
     }
     else
