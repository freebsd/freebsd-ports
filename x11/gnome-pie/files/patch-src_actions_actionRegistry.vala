--- src/actions/actionRegistry.vala.orig	2021-07-17 09:00:37 UTC
+++ src/actions/actionRegistry.vala
@@ -114,7 +114,7 @@ public class ActionRegistry : GLib.Object {
             case "application":
                 var file_name = uri.split("//")[1];
 
-                var desktop_file = GLib.File.new_for_path("/usr/share/applications/" + file_name);
+                var desktop_file = GLib.File.new_for_path("%%DESKTOPDIR%%" + file_name);
                 if (desktop_file.query_exists())
                     return new_for_desktop_file(desktop_file.get_path());
 
