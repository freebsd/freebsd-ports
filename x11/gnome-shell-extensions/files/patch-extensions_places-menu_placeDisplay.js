Don't error out if XDG isn't setup.
https://bugzilla.gnome.org/show_bug.cgi?id=741033

--- extensions/places-menu/placeDisplay.js.orig	2014-12-02 18:22:23.000000000 +0100
+++ extensions/places-menu/placeDisplay.js	2014-12-02 18:22:49.000000000 +0100
@@ -202,7 +202,7 @@
         let specials = [];
         for (let i = 0; i < DEFAULT_DIRECTORIES.length; i++) {
             let specialPath = GLib.get_user_special_dir(DEFAULT_DIRECTORIES[i]);
-            if (specialPath == homePath)
+            if (specialPath == null || specialPath == homePath)
                 continue;
 
             let file = Gio.File.new_for_path(specialPath), info;
