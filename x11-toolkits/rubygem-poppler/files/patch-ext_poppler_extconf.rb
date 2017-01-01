--- ext/poppler/extconf.rb.orig	2017-01-01 10:59:42.019656000 -0500
+++ ext/poppler/extconf.rb	2017-01-01 11:01:12.967319000 -0500
@@ -30,7 +30,7 @@
   require 'mkmf-gnome2'
 end
 
-["glib2", "atk"].each do |package|
+["cairo", "glib2", "atk", "gdk_pixbuf2"].each do |package|
   directory = "#{package}#{version_suffix}"
   build_dir = "#{directory}/tmp/#{RUBY_PLATFORM}/#{package}/#{RUBY_VERSION}"
   add_depend_package(package, "#{directory}/ext/#{package}",
