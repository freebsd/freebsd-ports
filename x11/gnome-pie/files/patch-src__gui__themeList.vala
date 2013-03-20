--- ./src/gui/themeList.vala.orig	2013-03-19 01:24:16.000000000 +0100
+++ ./src/gui/themeList.vala	2013-03-19 01:24:23.000000000 +0100
@@ -81,7 +81,7 @@
                     
                     this.on_select_new();
     
-                    Config.global.theme.load();
+                    //Config.global.theme.load();
                     Config.global.theme.load_images();
                     return false;
                 });  
