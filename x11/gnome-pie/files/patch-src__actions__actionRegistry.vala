--- ./src/actions/actionRegistry.vala.orig	2013-01-23 23:33:16.000000000 +0100
+++ ./src/actions/actionRegistry.vala	2013-01-24 21:41:21.000000000 +0100
@@ -108,7 +108,7 @@
             case "application":
                 var file_name = uri.split("//")[1];
                 
-                var desktop_file = GLib.File.new_for_path("/usr/share/applications/" + file_name);
+                var desktop_file = GLib.File.new_for_path("%%DESKTOPDIR%%/" + file_name);
                 if (desktop_file.query_exists())
                     return new_for_desktop_file(desktop_file.get_path());
 
