--- Makefile.PL.orig	Tue Jun 17 11:47:56 2003
+++ Makefile.PL	Fri Jul  2 12:44:59 2004
@@ -1,6 +1,5 @@
 use ExtUtils::MakeMaker;
 use Config;
-use blib '../Gtk';
 use Cwd;
 require '../Depends.pm';
 require '../tools/gendefs.pl';
@@ -9,8 +8,15 @@ $gpb = new ExtUtils::Depends('Gtk::Gdk::
 
 mkdir('build', 0777);
 
-$gpb->set_inc (`gdk-pixbuf-config --cflags`);
-$gpb->set_libs (`gdk-pixbuf-config --libs`);
+# hack to make it work with FreeBSD perl 5.8.4
+$::inc = `gdk-pixbuf-config --cflags`; chomp $::inc;
+$::inc .= " ";
+$::inc .= `gtk-config --cflags`; chomp $::inc;
+$gpb->set_inc ($::inc);
+$::libs = `gdk-pixbuf-config --libs`; chomp $::libs;
+$::libs .= " ";
+$::libs .= `gtk-config --libs`; chomp $::libs;
+$gpb->set_libs ($::libs);
 
 $gpb->add_typemaps (cwd() . '/pkg.typemap', cwd().'/build/GdkPixbufTypemap');
 $gpb->add_headers (qw( <gdk-pixbuf/gdk-pixbuf-loader.h> ));
