--- extconf.rb.orig	Tue Oct  9 02:49:22 2001
+++ extconf.rb	Wed Mar 20 21:53:56 2002
@@ -1,5 +1,11 @@
 require 'mkmf'
 
+gnome_config = with_config('gnome-config', 'gnome-config')
+
+while /^--/ =~ ARGV[0]
+  ARGV.shift
+end
+
 rbgtk_dir = "../gtk"
 rbgtk_dir = ARGV[0] if ARGV[0]
 unless FileTest.exist?(rbgtk_dir)
@@ -12,15 +18,14 @@
   raise "directry #{rbgnome_dir} not found.  Please specify Ruby-GNOME source dir."
 end
 
-$CFLAGS = "-I#{rbgtk_dir}/src -I#{rbgnome_dir}/src " + `gnome-config --cflags applets`.chomp
-$LDFLAGS = `gnome-config --libs applets`.chomp
+$CFLAGS += " -I#{rbgtk_dir}/src -I#{rbgnome_dir}/src " + `gnome-config --cflags applets`.chomp
+$LDFLAGS += ' ' + `#{gnome_config} --libs applets`.chomp
 
 have_library("X11", "XOpenDisplay") &&
 have_library("Xi", "XOpenDevice") &&
 have_library("Xext", "XextFindDisplay") &&
 have_library("Xmu", "XmuInternAtom") &&
-have_library("glib", "g_print") &&
-have_library("gtk", "gtk_init") &&
-have_library("panel_applet", "applet_widget_init") &&
-
+have_func("g_print") &&
+have_func("gtk_init") &&
+have_func("applet_widget_init") &&
 create_makefile('panel_applet')
