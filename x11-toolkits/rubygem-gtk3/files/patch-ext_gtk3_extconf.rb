--- ext/gtk3/extconf.rb.orig	2016-01-22 18:41:23.871812000 +0000
+++ ext/gtk3/extconf.rb	2016-01-22 18:43:47.587265000 +0000
@@ -39,6 +39,7 @@
 require "mkmf-gnome2"
 
 depended_packages = [
+  "cairo",
   "glib2",
   "gobject-introspection",
   "cairo-gobject",
