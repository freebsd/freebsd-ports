--- ext/gtk3/extconf.rb.orig	2017-07-08 14:41:53 UTC
+++ ext/gtk3/extconf.rb
@@ -39,6 +39,7 @@ package_id = "gtk+-3.0"
 require "mkmf-gnome2"
 
 depended_packages = [
+  "cairo",
   "glib2",
   "gobject-introspection",
   "cairo-gobject",
