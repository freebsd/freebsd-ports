--- subprojects/appmenu-gtk-module/src/datastructs-private.h.orig	2019-03-02 16:23:40 UTC
+++ subprojects/appmenu-gtk-module/src/datastructs-private.h
@@ -31,7 +31,7 @@
 struct _WindowData
 {
 	uint window_id;
-	ulong wayland_window_id;
+	gulong wayland_window_id;
 	GMenu *menu_model;
 	guint menu_model_export_id;
 	GSList *menus;
