--- extconf.rb.orig	2004-06-03 02:00:39.000000000 +0900
+++ extconf.rb	2006-07-10 15:53:56.000000000 +0900
@@ -2,12 +2,7 @@
 require 'mkmf-gnome2'
 
 PKGConfig.have_package('gtk+-2.0') or exit 1
-begin
-	require 'gtk2'
-rescue => e
-	$stderr.puts "Ruby/GTK couldn't be initialized ('#{e}')"
-	exit 1
-end
+have_header("rbgtk.h") or exit 1
 [ 'libintl.h', 'X11/Xatom.h', 'gdk/gdkx.h' ].each do |header|
 	have_header(header) or exit 1
 end
