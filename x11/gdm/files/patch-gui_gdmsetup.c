--- gui/gdmsetup.c.orig	Fri Jun  4 14:37:17 2004
+++ gui/gdmsetup.c	Fri Jun 11 15:42:28 2004
@@ -1983,7 +1983,7 @@
 		/* HACK! */
 		argv[0] = chown;
 		argv[1] = "-R";
-		argv[2] = "root:root";
+		argv[2] = "root:wheel";
 		argv[3] = quoted;
 		argv[4] = NULL;
 		simple_spawn_sync (argv);
