--- extconf.rb.orig	Sat Nov 23 13:32:52 2002
+++ extconf.rb	Sun Dec  8 00:40:16 2002
@@ -22,7 +22,7 @@
   config_cmd = with_config("pkg-config", "pkg-config libgnomeui-2.0")
   config_libs = "--libs"
   config_cflags = "--cflags"
-  config_library = "gnomeui gtkxmhtml"
+  config_library = ""
   version = `#{config_cmd} --version`
   if not version.chomp.empty? then
     $libs += ' ' + `#{config_cmd} #{config_libs} #{config_library}`.chomp
