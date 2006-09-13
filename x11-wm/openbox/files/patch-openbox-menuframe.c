--- openbox/menuframe.c.orig	Tue Sep 12 21:24:28 2006
+++ openbox/menuframe.c	Tue Sep 12 21:24:50 2006
@@ -675,12 +675,14 @@
 
 void menu_frame_hide_all()
 {
+    GList *it;
+
     if (config_submenu_show_delay) {
         /* remove any submenu open requests */
         ob_main_loop_timeout_remove(ob_main_loop,
                                     menu_entry_frame_submenu_timeout);
     }
-    GList *it = g_list_last(menu_frame_visible);
+    it = g_list_last(menu_frame_visible);
     if (it) 
         menu_frame_hide(it->data);
 }
