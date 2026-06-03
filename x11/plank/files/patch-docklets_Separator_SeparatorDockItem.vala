--- docklets/Separator/SeparatorDockItem.vala.orig	2025-09-17 00:18:24 UTC
+++ docklets/Separator/SeparatorDockItem.vala
@@ -252,8 +252,8 @@ namespace Docky {
       );
 
       string[] icon_paths = {
-        "/usr/share/icons",
-        "/usr/share/pixmaps",
+        "%%LOCALBASE%%/share/icons",
+        "%%LOCALBASE%%/share/pixmaps",
         GLib.Environment.get_home_dir () + "/.local/share/icons"
       };
 
