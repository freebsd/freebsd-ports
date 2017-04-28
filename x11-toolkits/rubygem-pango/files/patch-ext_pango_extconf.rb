--- ext/pango/extconf.rb.orig	2017-04-27 18:04:28 UTC
+++ ext/pango/extconf.rb
@@ -39,7 +39,7 @@ package_id = "pango"
 require "mkmf-gnome2"
 
 depended_packages = [
-  "glib2",
+  "cairo", "glib2", "pango"
 ]
 depended_packages.each do |package|
   directory = "#{package}#{version_suffix}"
