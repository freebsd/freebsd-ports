--- docklets/Separator/SeparatorDockItem.vala.orig	2026-08-04 01:49:12 UTC
+++ docklets/Separator/SeparatorDockItem.vala
@@ -289,8 +289,8 @@ namespace Docky {
       );
 
       string[] icon_paths = {
-        "/usr/share/icons",
-        "/usr/share/pixmaps",
+        "%%LOCALBASE%%/share/icons",
+        "%%LOCALBASE%%/share/pixmaps",
         GLib.Environment.get_home_dir () + "/.local/share/icons"
       };
 
