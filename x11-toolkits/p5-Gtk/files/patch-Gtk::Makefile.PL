--- Gtk/Makefile.PL.orig	Tue Jun 17 17:47:56 2003
+++ Gtk/Makefile.PL	Sun Oct 26 13:42:15 2003
@@ -40,8 +40,8 @@
 	$threadl = "";
 }
 
-$libs = `gtk-config --libs $threadl`;
-$inc = `gtk-config --cflags $threadl`;
+$libs = `$ENV{GTK_CONFIG} --libs $threadl`;
+$inc = `$ENV{GTK_CONFIG} --cflags $threadl`;
 $libs =~ s/\s+/ /g;
 $inc =~ s/\s+/ /g;
 
@@ -59,7 +59,7 @@
 
 $gtk_hverstr = sprintf("0x%02x%02x%02x", $gtk_major, $gtk_minor, $gtk_micro);
 
-push @defines, "-DGTK_HVER=$gtk_hverstr";
+push @defines, "-DGTK_HVER=$gtk_hverstr -o \$*.o";
 
 if (not defined $gtk_version) {
 	die "Unable to find  Gtk version...\n";
@@ -158,7 +158,7 @@
 	'XSPROTOARG' => '-noprototypes',
 	'depend' => $depend,
 	'dist' => { COMPRESS=>"gzip", SUFFIX=>"gz" },
-	'OPTIMIZE' => '-O2 -g',
+	'CCFLAGS' => '${CFLAGS}',
 	'MAN3PODS' => {
 		'cookbook.pod' => '$(INST_MAN3DIR)/Gtk::cookbook.3pm',
 		'Gtk.pm' => '$(INST_MAN3DIR)/Gtk.3pm',
@@ -187,12 +187,12 @@
 
 }
 
-sub MY::c_o {
-	package MY; # so that "SUPER" works right
-	my $inherited = shift->SUPER::c_o(@_);
-	$inherited =~ s/CCCMD.*$/$&\n\t\@if test -f `basename \$*.o` -a "`basename \$*.o`" != "\$*.o"; then mv `basename \$*.o` \$*.o; fi/mg;
-    $inherited;
-}
+#sub MY::c_o {
+#	package MY; # so that "SUPER" works right
+#	my $inherited = shift->SUPER::c_o(@_);
+#	$inherited =~ s/CCCMD.*$/$&\n\t\@if test -f `basename \$*.o` -a "`basename \$*.o`" != "\$*.o"; then mv `basename \$*.o` \$*.o; fi/mg;
+#    $inherited;
+#}
 
 sub MY::const_config
 {
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
