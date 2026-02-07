--- modules/launcher/gp-launcher-applet.c.orig	2024-10-06 18:30:22 UTC
+++ modules/launcher/gp-launcher-applet.c
@@ -33,7 +33,9 @@
 #include <glib/gi18n-lib.h>
 #include <gmenu-tree.h>
 #include <libgnome-desktop/gnome-systemd.h>
+#ifdef __linux__
 #include <systemd/sd-journal.h>
+#endif
 
 #include "gp-launcher-button.h"
 #include "gp-launcher-properties.h"
@@ -758,6 +760,7 @@ child_setup (gpointer user_data)
 static void
 child_setup (gpointer user_data)
 {
+#ifdef __linux__
   GAppInfo *info;
   const gchar *id;
   gint stdout_fd;
@@ -779,6 +782,7 @@ child_setup (gpointer user_data)
       dup2 (stderr_fd, STDERR_FILENO);
       close (stderr_fd);
     }
+#endif
 }
 
 static void
