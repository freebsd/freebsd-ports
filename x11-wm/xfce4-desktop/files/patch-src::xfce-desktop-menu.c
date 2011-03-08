--- src/xfce-desktop-menu.c.orig	2010-12-04 06:20:14.000000000 -0600
+++ src/xfce-desktop-menu.c	2011-03-05 19:58:16.416523605 -0600
@@ -99,7 +99,8 @@ xfce_desktop_menu_reload(XfceDesktopMenu
      * recursively.  same deal for _something_changed(). */
     DBG("Schedule menu reload");
     if(!desktop_menu->idle_id)
-        desktop_menu->idle_id = g_idle_add(_generate_menu_idled, desktop_menu);
+        /* just regen when idle. */
+        _generate_menu(desktop_menu);
 }
 
 /*
