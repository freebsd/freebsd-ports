--- Makefile.PL.orig	Wed Aug  9 22:30:38 2000
+++ Makefile.PL	Tue Sep 12 11:54:31 2000
@@ -102,10 +102,10 @@
 	$threadl = "";
 }
 
-$libs = `gtk-config --libs $threadl`;
+$libs = `$ENV{GTK_CONFIG} --libs $threadl`;
 $libs = "-L/usr/X11R6/lib -lgtk -lgdk -lglib -lX11 -lXext" if not defined $libs;
 
-$inc = `gtk-config --cflags $threadl`;
+$inc = `$ENV{GTK_CONFIG} --cflags $threadl`;
 
 $libs =~ s/\s+/ /g;
 $inc =~ s/\s+/ /g;
@@ -167,7 +167,7 @@
 
 # build the keysyms mapping
 {
-	my ($incfile) = `gtk-config --prefix`;
+	my ($incfile) = `$ENV{GTK_CONFIG} --prefix`;
 	chomp($incfile);
 	$incfile .= "/include/gdk/gdkkeysyms.h";
 
@@ -470,7 +470,7 @@
 sub gtk_version {
 	my($result);
 
-	$result = `gtk-config --version`;
+	$result = `$ENV{GTK_CONFIG} --version`;
 	chomp $result;
 	
 	if (not defined $result) {
