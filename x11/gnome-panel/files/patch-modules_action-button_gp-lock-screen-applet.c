--- modules/action-button/gp-lock-screen-applet.c.orig	2023-07-10 18:48:25 UTC
+++ modules/action-button/gp-lock-screen-applet.c
@@ -20,7 +20,9 @@
 
 #include <gio/gdesktopappinfo.h>
 #include <glib/gi18n-lib.h>
+#ifdef __linux__
 #include <systemd/sd-journal.h>
+#endif
 
 #include "gpab-screensaver-gen.h"
 
@@ -209,6 +211,7 @@ screensaver_cb (GSimpleAction *action,
 static void
 child_setup (gpointer user_data)
 {
+#ifdef __linux__
   GAppInfo *info;
   const gchar *id;
   gint stdout_fd;
@@ -230,6 +233,7 @@ child_setup (gpointer user_data)
       dup2 (stderr_fd, STDERR_FILENO);
       close (stderr_fd);
     }
+#endif
 }
 
 static void
