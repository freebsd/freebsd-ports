--- Gtk/Makefile.PL.orig	Mon Mar 12 02:44:49 2001
+++ Gtk/Makefile.PL	Mon Mar 12 02:55:54 2001
@@ -38,8 +38,8 @@
 	$threadl = "";
 }
 
-$libs = `gtk-config --libs $threadl`;
-$inc = `gtk-config --cflags $threadl`;
+$libs = `$ENV{GTK_CONFIG} --libs $threadl`;
+$inc = `$ENV{GTK_CONFIG} --cflags $threadl`;
 $libs =~ s/\s+/ /g;
 $inc =~ s/\s+/ /g;
 
@@ -192,14 +192,14 @@
 sub gtk_version {
 	my($result);
 
-	$result = `gtk-config --version`;
+	$result = `$ENV{GTK_CONFIG} --version`;
 	chomp $result;
 	return $result;
 }
 
 # build the keysyms mapping
 sub build_ksyms {
-	my ($incfile) = `gtk-config --prefix`;
+	my ($incfile) = `$ENV{GTK_CONFIG} --prefix`;
 	chomp($incfile);
 	$incfile .= "/include/gdk/gdkkeysyms.h";
 
