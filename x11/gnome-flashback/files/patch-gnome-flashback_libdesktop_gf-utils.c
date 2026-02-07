--- gnome-flashback/libdesktop/gf-utils.c.orig	2025-04-26 13:51:39 UTC
+++ gnome-flashback/libdesktop/gf-utils.c
@@ -20,11 +20,14 @@
 
 #include <gio/gdesktopappinfo.h>
 #include <gtk/gtk.h>
+#ifdef __linux__
 #include <systemd/sd-journal.h>
+#endif
 
 static void
 child_setup (gpointer user_data)
 {
+#ifdef __linux__
   GAppInfo *app_info;
   const gchar *id;
   gint stdout_fd;
@@ -46,6 +49,7 @@ child_setup (gpointer user_data)
       dup2 (stderr_fd, STDERR_FILENO);
       close (stderr_fd);
     }
+#endif
 }
 
 static void
