--- Makefile.PL.orig	Mon Mar 12 02:44:15 2001
+++ Makefile.PL	Mon Mar 12 02:55:13 2001
@@ -13,11 +13,11 @@
 
 %detect = (
 	gtk => {order => 1, dir => 'Gtk', needed => 1, 
-		check => sub {cconfig('gtk-config --version', '1\.2\.')}},
+		check => sub {cconfig("$ENV{GTK_CONFIG} --version", '1\.2\.')}},
 	gdkimlib => {order => 2, dir => 'GdkImlib', 
 		check => sub {cconfig('imlib-config --version', '1\.9\.') && `imlib-config --libs-gdk`}},
 	gtkglarea => {order => 2, dir => 'GtkGLArea',
-		check => sub {cconfig('gtk-config --version', '1\.2\.')}},
+		check => sub {cconfig("$ENV{GTK_CONFIG} --version", '1\.2\.')}},
 	gdkpixbuf => {order => 2, dir => 'GdkPixbuf',
 		check => sub {cconfig('gdk-pixbuf-config --version', '0\.9\.')}},
 	gtkhtml => {order => 2, dir => 'GtkHTML',
