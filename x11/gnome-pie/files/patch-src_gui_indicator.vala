--- src/gui/indicator.vala.orig	2021-07-17 09:00:37 UTC
+++ src/gui/indicator.vala
@@ -79,7 +79,7 @@ public class Indicator : GLib.Object {
 
             string path = "";
             try {
-                path = GLib.Path.get_dirname(GLib.FileUtils.read_link("/proc/self/exe"))+"/resources";
+                path = "%%DATADIR%%/resouces";
             } catch (GLib.FileError e) {
                 warning("Failed to get path of executable!");
             }
@@ -91,11 +91,7 @@ public class Indicator : GLib.Object {
         #else
             this.indicator = new Gtk.StatusIcon();
             try {
-                var file = GLib.File.new_for_path(GLib.Path.build_filename(
-                    GLib.Path.get_dirname(GLib.FileUtils.read_link("/proc/self/exe"))+"/resources",
-                    icon + ".svg"
-                ));
-
+		var file = GLib.File.new_for_path(GLib.Path.build_filename("%%PREFIX%%/share/icons/hicolor/scalable/apps/", icon + ".svg"));
                 if (!file.query_exists())
                   this.indicator.set_from_icon_name(icon);
                 else
