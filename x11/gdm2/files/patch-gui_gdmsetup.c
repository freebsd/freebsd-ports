--- gui/gdmsetup.c.orig	Mon Apr 12 14:24:57 2004
+++ gui/gdmsetup.c	Mon Apr 12 14:25:00 2004
@@ -1962,7 +1962,7 @@
 			success = TRUE;
 
 			/* HACK! */
-			cmd = g_strdup_printf ("%s -R root.root %s", chown, quoted);
+			cmd = g_strdup_printf ("%s -R root:wheel %s", chown, quoted);
 			system (cmd);
 			g_free (cmd);
 
