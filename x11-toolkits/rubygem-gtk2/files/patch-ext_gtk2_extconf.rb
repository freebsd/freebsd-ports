--- ext/gtk2/extconf.rb.orig	2017-04-28 06:44:21 UTC
+++ ext/gtk2/extconf.rb
@@ -33,7 +33,7 @@ end
 
 have_func("rb_errinfo")
 
-["glib2", "pango"].each do |package|
+["cairo", "glib2", "pango"].each do |package|
   directory = "#{package}#{version_suffix}"
   build_dir = "#{directory}/tmp/#{RUBY_PLATFORM}/#{package}/#{RUBY_VERSION}"
   add_depend_package(package, "#{directory}/ext/#{package}",
