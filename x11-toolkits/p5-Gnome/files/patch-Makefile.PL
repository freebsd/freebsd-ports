--- Makefile.PL.orig	Mon Mar 12 06:06:22 2001
+++ Makefile.PL	Mon Mar 12 06:08:32 2001
@@ -1,6 +1,4 @@
 use ExtUtils::MakeMaker;
-use blib '../Gtk';
-use blib '../GdkImlib';
 use Cwd;
 require '../Depends.pm';
 require '../tools/gendefs.pl';
@@ -88,7 +86,6 @@
 	'XSOPT' => '-noversioncheck',
 	'DEFINE'    => join(' ',@defines),
 	'dist' => { COMPRESS=>"gzip", SUFFIX=>"gz" },
-	'OPTIMIZE' => '-O2 -g',
 	'depend' => $depend,
 	$gnome->get_makefile_vars,
 );
