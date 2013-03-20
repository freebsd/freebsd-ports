--- ./src/utilities/paths.vala.orig	2013-03-17 12:15:02.000000000 +0100
+++ ./src/utilities/paths.vala	2013-03-19 01:34:39.000000000 +0100
@@ -71,21 +71,21 @@
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
@@ -115,7 +115,7 @@
     
         // get path of executable
         try {
-            executable = GLib.File.new_for_path(GLib.FileUtils.read_link("/proc/self/exe")).get_path();
+            executable = GLib.File.new_for_path("%%PREFIX%%/bin/gnome-pie").get_path();
         } catch (GLib.FileError e) {
             warning("Failed to get path of executable!");
         }
