--- gui/gdmsetup.c.orig	Thu Jun 30 16:47:06 2005
+++ gui/gdmsetup.c	Sun Jul  3 15:17:55 2005
@@ -3270,7 +3274,7 @@ theme_install_response (GtkWidget *choos
 		/* HACK! */
 		argv[0] = chown;
 		argv[1] = "-R";
-		argv[2] = "root:root";
+		argv[2] = "root:wheel";
 		argv[3] = quoted;
 		argv[4] = NULL;
 		simple_spawn_sync (argv);
