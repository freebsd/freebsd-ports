--- gui/gdmsetup.c.orig	Sun Aug  4 16:08:52 2002
+++ gui/gdmsetup.c	Sun Aug  4 16:09:09 2002
@@ -1512,7 +1512,7 @@
 			success = TRUE;
 
 			/* HACK! */
-			cmd = g_strdup_printf ("/bin/chown -R root.root %s", dir);
+			cmd = g_strdup_printf ("/usr/sbin/chown -R gdm:gdm %s", dir);
 			system (cmd);
 			g_free (cmd);
 
