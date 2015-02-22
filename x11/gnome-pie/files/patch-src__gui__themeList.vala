--- src/gui/themeList.vala.orig	2015-01-23 11:49:05 UTC
+++ src/gui/themeList.vala
@@ -81,7 +81,7 @@ class ThemeList : Gtk.TreeView {
                     
                     this.on_select_new();
     
-                    Config.global.theme.load();
+                    //Config.global.theme.load();
                     Config.global.theme.load_images();
                     return false;
                 });  
