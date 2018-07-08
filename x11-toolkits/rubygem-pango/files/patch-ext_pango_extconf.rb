--- ext/pango/extconf.rb.orig	2018-07-07 04:30:00 UTC
+++ ext/pango/extconf.rb
@@ -39,7 +39,7 @@ package_id = "pango"
 require "mkmf-gnome2"
 
 depended_packages = [
-  "glib2",
+  "cairo", "glib2", "pango",
   "gobject-introspection",
 ]
 depended_packages.each do |package|
