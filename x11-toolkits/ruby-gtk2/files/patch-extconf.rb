--- extconf.rb.orig	Wed Jan  9 05:21:22 2002
+++ extconf.rb	Wed Mar 20 22:12:37 2002
@@ -8,24 +8,13 @@
 # detect GTK+ configurations
 #
 if /mswin32/ !~ PLATFORM
-  config_cmds = ["gtk-config"]
-  while /^--/ =~ ARGV[0]
-    ARGV.shift
-  end
-  if ARGV.size > 0
-    config_cmds.unshift(ARGV[0])
-  end
+  config_cmd = with_config("gtk-config", "gtk-config")
   
   begin
-    config_cmds.each do |config_cmd|
-      version = `#{config_cmd} --version`
-      if not version.chomp.empty?
-	config_libs, config_cflags = "--libs", "--cflags"
-	$LDFLAGS, *libs = `#{config_cmd} #{config_libs}`.chomp.split(/(-l.*)/)
-	$libs = libs.join(' ') + ' ' + $libs
-	$CFLAGS = `#{config_cmd} #{config_cflags}`.chomp
-	break
-      end
+    version = `#{config_cmd} --version`
+    if not version.chomp.empty?
+      $LDFLAGS += ' ' + `#{config_cmd} --libs`.chomp
+      $CFLAGS += ' ' + `#{config_cmd} --cflags`.chomp
     end
   rescue
     $LDFLAGS = '-L/usr/X11R6/lib -L/usr/local/lib'
