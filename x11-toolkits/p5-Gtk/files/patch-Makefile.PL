--- Makefile.PL.orig	Sat Mar 24 20:18:40 2001
+++ Makefile.PL	Sun May 27 22:43:07 2001
@@ -14,12 +14,12 @@
 
 %detect = (
 	gtk => {order => 1, dir => 'Gtk', needed => 1, 
-		check => sub {cconfig('gtk-config --version', '1\.2\.')}},
+		check => sub {cconfig("$ENV{GTK_CONFIG} --version", '1\.2\.')}},
 	gdkimlib => {order => 2, dir => 'GdkImlib', 
 		check => sub {cconfig('imlib-config --version', '1\.9\.') && `imlib-config --libs-gdk`}},
 	gtkglarea => {order => 2, dir => 'GtkGLArea',
-		check => sub {ccompile('#include <gtkgl/gtkglarea.h>', "", `gtk-config --cflags`,
-					"-lgtkgl  -lGL -lGLU " . `gtk-config --libs`)}},
+		check => sub {ccompile('#include <gtkgl/gtkglarea.h>', "", `$ENV{GTK_CONFIG} --cflags`,
+					"-lgtkgl  -lGL -lGLU " . `$ENV{GTK_CONFIG} --libs`)}},
 	gdkpixbuf => {order => 2, dir => 'GdkPixbuf',
 		check => sub {cconfig('gdk-pixbuf-config --version', '0\.(9|1\d)\.?')}},
 	gtkhtml => {order => 2, dir => 'GtkHTML',
