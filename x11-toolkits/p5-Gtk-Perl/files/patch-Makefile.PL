--- Makefile.PL.orig	Tue Jun 26 23:17:02 2001
+++ Makefile.PL	Wed Apr  3 16:15:10 2002
@@ -15,12 +15,12 @@
 
 %detect = (
 	gtk => {order => 1, dir => 'Gtk', needed => 1, 
-		check => sub {cconfig('gtk-config --version', '1\.2\.')}},
+		check => sub {cconfig("$ENV{GTK_CONFIG} --version", '1\.2\.')}},
 	gdkimlib => {order => 2, dir => 'GdkImlib', depends => [qw(gtk)],
 		check => sub {cconfig('imlib-config --version', '1\.9\.') && `imlib-config --libs-gdk`}},
 	gtkglarea => {order => 2, dir => 'GtkGLArea', depends => [qw(gtk)],
-		check => sub {ccompile('#include <gtkgl/gtkglarea.h>', "", `gtk-config --cflags`,
-					"-lgtkgl  -lGL -lGLU " . `gtk-config --libs`)}},
+		check => sub {ccompile('#include <gtkgl/gtkglarea.h>', "", `$ENV{GTK_CONFIG} --cflags`,
+					"-lgtkgl  -lGL -lGLU " . `$ENV{GTK_CONFIG} --libs`)}},
 	gdkpixbuf => {order => 2, dir => 'GdkPixbuf', depends => [qw(gtk)],
 		check => sub {cconfig('gdk-pixbuf-config --version', '0\.(8|9|1\d)\.?')}},
 	gtkhtml => {order => 2, dir => 'GtkHTML', depends => [qw(gtk)],
