--- Makefile.PL.orig	Mon Mar 12 03:29:15 2001
+++ Makefile.PL	Mon Mar 12 03:29:27 2001
@@ -1,6 +1,5 @@
 use ExtUtils::MakeMaker;
 use Cwd;
-use blib '../Gtk';
 require '../Depends.pm';
 
 $imlib = new ExtUtils::Depends ('Gtk::Gdk::ImlibImage', 'Gtk');
