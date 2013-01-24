--- ./src/utilities/paths.vala.orig	2013-01-23 23:33:16.000000000 +0100
+++ ./src/utilities/paths.vala	2013-01-24 21:41:21.000000000 +0100
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
