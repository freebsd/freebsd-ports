--- ext/pango/extconf.rb.orig	2016-01-19 22:13:22 UTC
+++ ext/pango/extconf.rb
@@ -33,7 +33,7 @@ end
 ruby_header = "ruby.h"
 have_func("rb_errinfo", ruby_header)
 
-["glib2"].each do |package|
+["cairo", "pango", "glib2"].each do |package|
   directory = "#{package}#{version_suffix}"
   build_dir = "#{directory}/tmp/#{RUBY_PLATFORM}/#{package}/#{RUBY_VERSION}"
   add_depend_package(package, "#{directory}/ext/#{package}",
