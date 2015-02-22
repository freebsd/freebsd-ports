--- src/utilities/paths.vala.orig	2015-02-10 20:42:17 UTC
+++ src/utilities/paths.vala
@@ -71,21 +71,21 @@ public class Paths : GLib.Object {
     /// usually /usr/share/gnome-pie/themes.
     /////////////////////////////////////////////////////////////////////
 
-    public static string global_themes { get; private set; default=""; }
+    public static string global_themes { get; private set; default="%%DATADIR%%/themes"; }
 
     /////////////////////////////////////////////////////////////////////
     /// The directory containing locale files
     /// usually /usr/share/locale.
     /////////////////////////////////////////////////////////////////////
 
-    public static string locales { get; private set; default=""; }
+    public static string locales { get; private set; default="%%PREFIX%%/share/locale"; }
 
     /////////////////////////////////////////////////////////////////////
     /// The directory containing UI declaration files
     /// usually /usr/share/gnome-pie/ui/.
     /////////////////////////////////////////////////////////////////////
 
-    public static string ui_files { get; private set; default=""; }
+    public static string ui_files { get; private set; default="%%DATADIR%%/ui"; }
 
     /////////////////////////////////////////////////////////////////////
     /// The autostart file of gnome-pie_config
@@ -115,7 +115,7 @@ public class Paths : GLib.Object {
 
         // get path of executable
         try {
-            executable = GLib.File.new_for_path(GLib.FileUtils.read_link("/proc/self/exe")).get_path();
+            executable = GLib.File.new_for_path("%%PREFIX%%/bin/gnome-pie").get_path();
         } catch (GLib.FileError e) {
             warning("Failed to get path of executable!");
         }
@@ -128,12 +128,12 @@ public class Paths : GLib.Object {
             Gtk.IconTheme.get_default().append_search_path(path);
         }
 
-        Gtk.IconTheme.get_default().append_search_path("/usr/share/pixmaps/");
+        Gtk.IconTheme.get_default().append_search_path("%%LOCALBASE%%/share/pixmaps/");
 
         // get global paths
         var default_dir = GLib.File.new_for_path("/usr/share/gnome-pie/");
         if(!default_dir.query_exists()) {
-            default_dir = GLib.File.new_for_path("/usr/local/share/gnome-pie/");
+            default_dir = GLib.File.new_for_path("%%DATADIR%%/");
 
             if(!default_dir.query_exists()) {
                 default_dir = GLib.File.new_for_path(GLib.Path.get_dirname(
@@ -149,9 +149,9 @@ public class Paths : GLib.Object {
         if(locale_dir.query_exists()) {
             locale_dir = GLib.File.new_for_path("/usr/share/locale");
         } else {
-            locale_dir = GLib.File.new_for_path("/usr/local/share/locale/de/LC_MESSAGES/gnomepie.mo");
+            locale_dir = GLib.File.new_for_path("%%LOCALBASE%%/share/locale/de/LC_MESSAGES/gnomepie.mo");
             if(locale_dir.query_exists()) {
-                locale_dir = GLib.File.new_for_path("/usr/local/share/locale");
+                locale_dir = GLib.File.new_for_path("%%LOCALBASE%%/share/locale");
             } else {
                 locale_dir = GLib.File.new_for_path(GLib.Path.get_dirname(
                     executable)).get_child("resources/locale/de/LC_MESSAGES/gnomepie.mo");
