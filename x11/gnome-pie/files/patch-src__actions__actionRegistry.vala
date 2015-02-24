--- src/actions/actionRegistry.vala.orig	2015-01-23 11:49:05 UTC
+++ src/actions/actionRegistry.vala
@@ -108,7 +108,7 @@ public class ActionRegistry : GLib.Objec
             case "application":
                 var file_name = uri.split("//")[1];
                 
-                var desktop_file = GLib.File.new_for_path("/usr/share/applications/" + file_name);
+                var desktop_file = GLib.File.new_for_path("%%DATADIR%%/applications/" + file_name);
                 if (desktop_file.query_exists())
                     return new_for_desktop_file(desktop_file.get_path());
 
