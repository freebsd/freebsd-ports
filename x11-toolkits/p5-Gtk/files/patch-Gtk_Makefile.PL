--- Gtk/Makefile.PL.orig	Sat Mar 24 18:35:10 2001
+++ Gtk/Makefile.PL	Sun May 27 22:41:52 2001
@@ -40,8 +40,8 @@
 	$threadl = "";
 }
 
-$libs = `gtk-config --libs $threadl`;
-$inc = `gtk-config --cflags $threadl`;
+$libs = `$ENV{GTK_CONFIG} --libs $threadl`;
+$inc = `$ENV{GTK_CONFIG} --cflags $threadl`;
 $libs =~ s/\s+/ /g;
 $inc =~ s/\s+/ /g;
 
@@ -160,3 +160,3 @@
 	'dist' => { COMPRESS=>"gzip", SUFFIX=>"gz" },
-	'OPTIMIZE' => '-O2 -g',
+	'CCFLAGS' => '${CFLAGS}',
 	'MAN3PODS' => {
@@ -207,14 +207,14 @@
 sub gtk_version {
 	my($result);
 
-	$result = `gtk-config --version`;
+	$result = `$ENV{GTK_CONFIG} --version`;
 	chomp $result;
 	return $result;
 }
 
 # build the keysyms mapping
 sub build_ksyms {
-	my ($dir) = `gtk-config --prefix`;
+	my ($dir) = `$ENV{GTK_CONFIG} --prefix`;
 	chomp($dir);
 	my $incfile;
 	foreach ("/", "/gtk-1.2") {
