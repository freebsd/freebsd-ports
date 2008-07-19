--- src/panel.h.orig	2008-07-17 14:40:37.000000000 +0800
+++ src/panel.h	2008-07-17 14:41:21.000000000 +0800
@@ -190,6 +190,7 @@
 void panel_set_dock_type(Panel *p);
 void panel_set_orientation(Panel *p);
 void panel_update_background( Panel* p );
+void panel_destroy( Panel* p );
 
 extern const char* lxpanel_get_file_manager();
 extern const char* lxpanel_get_terminal();
