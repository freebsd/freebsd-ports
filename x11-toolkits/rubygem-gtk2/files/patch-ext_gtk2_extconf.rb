--- ext/gtk2/extconf.rb.orig	2016-01-19 22:27:15 UTC
+++ ext/gtk2/extconf.rb
@@ -33,7 +33,7 @@ end
 
 have_func("rb_errinfo")
 
-["glib2", "atk", "pango", "gdk_pixbuf2"].each do |package|
+["cairo", "glib2", "atk", "pango", "gdk_pixbuf2"].each do |package|
   directory = "#{package}#{version_suffix}"
   build_dir = "#{directory}/tmp/#{RUBY_PLATFORM}/#{package}/#{RUBY_VERSION}"
   add_depend_package(package, "#{directory}/ext/#{package}",
