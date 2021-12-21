--- ext/gtk2/extconf.rb.orig	2018-04-11 14:13:44 UTC
+++ ext/gtk2/extconf.rb
@@ -34,6 +34,7 @@ end
 have_func("rb_errinfo")
 
 [
+  "cairo",
   "glib2",
   "atk",
   "pango",
