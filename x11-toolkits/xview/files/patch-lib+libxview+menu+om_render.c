--- ./lib/libxview/menu/om_render.c.orig	Tue Jun 29 07:16:26 1993
+++ ./lib/libxview/menu/om_render.c	Sat Apr  1 18:25:24 2000
@@ -470,9 +470,9 @@ menu_render(menu, group, parent)
      * Define the menu and shadow window dimensions.  Note: shadow rect width &
      * height = menu rect width & height
      */
-    xv_set(m->window, XV_RECT, m->fs_menurect, 0);
+    xv_set(m->window, XV_RECT, &m->fs_menurect, 0);
     if (!m->group_info->three_d)
-	xv_set(m->shadow_window, XV_RECT, shadowrect, 0);
+	xv_set(m->shadow_window, XV_RECT, &shadowrect, 0);
 
     XFlush(XV_DISPLAY_FROM_WINDOW(m->window));
 
