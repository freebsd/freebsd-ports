--- extconf.rb.orig	Sat Sep 23 06:00:02 2000
+++ extconf.rb	Wed Feb 28 20:59:59 2001
@@ -21,11 +21,12 @@
   config_library = "gnomeui"
   version = `#{config_cmd} --version`
   if not version.chomp.empty? then
-    $LDFLAGS, *libs =
+    ldflags, *libs =
       `#{config_cmd} #{config_libs} #{config_library}`.chomp.split(/(-l.*)/)
+    $LDFLAGS += ldflags
     $libs = libs.join(' ') + ' ' + $libs
-    $CFLAGS = `#{config_cmd} #{config_cflags} #{config_library}`.chomp
-    $CFLAGS = $CFLAGS + " -DHAVE_GDKIMLIB -I../../gtk/src  -I../../gdkimlib"
+    $CFLAGS += `#{config_cmd} #{config_cflags} #{config_library}`.chomp
+    $CFLAGS += " -DHAVE_GDKIMLIB -I../../gtk/src  -I../../gdkimlib"
   else
     raise "can't find a config command"
   end
