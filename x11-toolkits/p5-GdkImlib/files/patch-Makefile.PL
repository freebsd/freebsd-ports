--- Makefile.PL.orig	Fri Oct 13 00:20:57 2000
+++ Makefile.PL	Mon Oct 30 03:51:44 2000
@@ -1,5 +1,4 @@
 use ExtUtils::MakeMaker;
-use blib '..';
 use Gtk::Install::Files;
 use Cwd;
 require '../Depends.pm';
@@ -27,8 +26,8 @@
 	$typemaps, [keys %defs], [@defines], [@headers], $pm);
 
 foreach (@typemaps) {
-	print "Add typemap: $Gtk::Install::Files::CORE/$_\n";
-	push(@$typemaps, cwd() .'/'.$Gtk::Install::Files::CORE . '/'. $_);
+	print "Add typemap: $Gtk::Install::Files::CORE$_\n";
+	push(@$typemaps, '/'.$Gtk::Install::Files::CORE . $_);
 }
 
 push(@defines, @Gtk::Install::Files::defines);
