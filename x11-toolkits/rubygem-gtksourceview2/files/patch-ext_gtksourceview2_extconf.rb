--- ext/gtksourceview2/extconf.rb.orig	2017-04-28 17:05:47 UTC
+++ ext/gtksourceview2/extconf.rb
@@ -31,6 +31,7 @@ rescue LoadError
 end
 
 [
+  "cairo",
   "glib2",
   "gobject-introspection",
   "gio2",
