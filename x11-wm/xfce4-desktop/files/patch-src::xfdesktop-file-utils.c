--- ./src/xfdesktop-file-utils.c.orig	2011-04-22 13:21:52.000000000 -0500
+++ ./src/xfdesktop-file-utils.c	2011-04-27 12:32:33.676427006 -0500
@@ -49,7 +49,9 @@
 
 #include <libxfce4ui/libxfce4ui.h>
 
+#ifdef HAVE_LIBEXO
 #include <exo/exo.h>
+#endif
 
 #include <dbus/dbus-glib-lowlevel.h>

