--- Makefile.PL.orig	Tue Jun 20 18:36:15 2000
+++ Makefile.PL	Mon Oct 30 03:52:25 2000
@@ -1,7 +1,5 @@
 use ExtUtils::MakeMaker;
 use File::Basename;
-use blib '..';
-use blib '../GdkImlib';
 use Gtk::Install::Files;
 use Gtk::Gdk::ImlibImage::Install::Files;
 use Cwd;
@@ -46,12 +44,12 @@
 	$typemaps, [keys %defs], [@defines], [@headers], $pm);
 
 foreach (@typemaps) {
-	print "Add typemap: $Gtk::Install::Files::CORE/$_\n";
-	push(@$typemaps, cwd() .'/'.$Gtk::Install::Files::CORE . '/'. $_);
+	print "Add typemap: $Gtk::Install::Files::CORE$_\n";
+	push(@$typemaps, '/'.$Gtk::Install::Files::CORE . $_);
 }
 foreach (@Gtk::Gdk::ImlibImage::Install::Files::typemaps) {
-	print "Add typemap: $Gtk::Gdk::ImlibImage::Install::Files::CORE/$_\n";
-	push(@$typemaps, cwd() .'/'.$Gtk::Gdk::ImlibImage::Install::Files::CORE . '/'. $_);
+	print "Add typemap: $Gtk::Gdk::ImlibImage::Install::Files::CORE$_\n";
+	push(@$typemaps, '/'.$Gtk::Gdk::ImlibImage::Install::Files::CORE . $_);
 }
 push(@defines, @Gtk::Install::Files::defines, @Gtk::Gdk::ImlibImage::Install::Files::defines);
 #push(@defines, '-I../build', '-Ibuild', '-I.', '-I../Gtk');
@@ -127,7 +125,6 @@
 	'LIBS' => [$libs],
 	'OBJECT' => $object,
 	'clean' => {FILES => join(' ', @clean) },
-	'OPTIMIZE' => '-O2 -g',
 	#'LDFROM' => $ldfrom,
 	'depend' => $depend,
 );
