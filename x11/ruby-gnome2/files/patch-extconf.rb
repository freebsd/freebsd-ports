--- extconf.rb.orig	Mon Feb  4 13:00:24 2002
+++ extconf.rb	Wed Mar 20 22:03:22 2002
@@ -7,25 +7,17 @@
 #
 # detect Gnome configurations
 #
-config_cmds = [
-    ["gnome-config", "--libs", "--cflags", "gnome", "gnomeui"],
-]
-if ARGV.size > 0
-  config_cmds.unshift([ARGV[0], "--libs", "--cflags"])
-end
 
 begin
-  config_cmd = "gnome-config"
+  config_cmd = with_config("gnome-config", "gnome-config")
   config_libs = "--libs"
   config_cflags = "--cflags"
   config_library = "gnomeui"
   version = `#{config_cmd} --version`
   if not version.chomp.empty? then
-    $LDFLAGS, *libs =
-      `#{config_cmd} #{config_libs} #{config_library}`.chomp.split(/(-l.*)/)
-    $libs = libs.join(' ') + ' ' + $libs
-    $CFLAGS = `#{config_cmd} #{config_cflags} #{config_library}`.chomp
-    $CFLAGS = $CFLAGS + " -DHAVE_GDKIMLIB -I../../gtk/src  -I../../gdkimlib"
+    $LDFLAGS += ' ' + `#{config_cmd} #{config_libs} #{config_library}`.chomp
+    $CFLAGS += " -DHAVE_GDKIMLIB -I../../gtk/src  -I../../gdkimlib " +
+      `#{config_cmd} #{config_cflags} #{config_library}`.chomp
   else
     raise "Can't find a config command"
   end
