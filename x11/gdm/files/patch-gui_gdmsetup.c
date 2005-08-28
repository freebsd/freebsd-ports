--- gui/gdmsetup.c.orig	Thu Jun 30 16:47:06 2005
+++ gui/gdmsetup.c	Mon Jul  4 02:53:12 2005
@@ -3270,7 +3271,7 @@ theme_install_response (GtkWidget *choos
 		/* HACK! */
 		argv[0] = chown;
 		argv[1] = "-R";
-		argv[2] = "root:root";
+		argv[2] = "root:wheel";
 		argv[3] = quoted;
 		argv[4] = NULL;
 		simple_spawn_sync (argv);
