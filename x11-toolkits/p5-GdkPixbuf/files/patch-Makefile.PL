--- Makefile.PL.orig	Tue Jun 20 18:37:48 2000
+++ Makefile.PL	Mon Oct 30 03:53:05 2000
@@ -1,6 +1,5 @@
 use ExtUtils::MakeMaker;
 use File::Basename;
-use blib '..';
 use Gtk::Install::Files;
 use Cwd;
 require '../Depends.pm';
@@ -29,8 +28,8 @@
 	$typemaps, [keys %defs], [@defines], [@headers], $pm);
 
 foreach (@typemaps) {
-	print "Add typemap: $Gtk::Install::Files::CORE/$_\n";
-	push(@$typemaps, cwd() .'/'.$Gtk::Install::Files::CORE . '/'. $_);
+	print "Add typemap: $Gtk::Install::Files::CORE$_\n";
+	push(@$typemaps, '/'.$Gtk::Install::Files::CORE . $_);
 }
 
 push(@defines, @Gtk::Install::Files::defines);
