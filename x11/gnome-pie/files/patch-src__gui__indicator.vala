--- ./src/gui/indicator.vala.orig	2013-03-19 01:40:47.000000000 +0100
+++ ./src/gui/indicator.vala	2013-03-19 01:41:57.000000000 +0100
@@ -93,10 +93,7 @@
         #else
             this.indicator = new Gtk.StatusIcon();
             try {
-                var file = GLib.File.new_for_path(GLib.Path.build_filename(
-                    GLib.Path.get_dirname(GLib.FileUtils.read_link("/proc/self/exe"))+"/resources",
-                    icon + ".svg"
-                ));
+                var file = GLib.File.new_for_path(GLib.Path.build_filename("%%DATADIR%%/resources", icon + ".svg"));
 
                 if (!file.query_exists())
                   this.indicator.set_from_icon_name(icon);
