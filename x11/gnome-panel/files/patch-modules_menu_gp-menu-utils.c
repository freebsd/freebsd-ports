--- modules/menu/gp-menu-utils.c.orig	2024-10-06 18:30:22 UTC
+++ modules/menu/gp-menu-utils.c
@@ -20,7 +20,9 @@
 #include <glib/gi18n-lib.h>
 #include <gtk/gtk.h>
 #include <libgnome-desktop/gnome-systemd.h>
+#ifdef __linux__
 #include <systemd/sd-journal.h>
+#endif
 
 #include "gp-menu-utils.h"
 
@@ -262,6 +264,7 @@ child_setup (gpointer user_data)
 static void
 child_setup (gpointer user_data)
 {
+#ifdef __linux__
   GAppInfo *info;
   const gchar *id;
   gint stdout_fd;
@@ -283,6 +286,7 @@ child_setup (gpointer user_data)
       dup2 (stderr_fd, STDERR_FILENO);
       close (stderr_fd);
     }
+#endif
 }
 
 static void
