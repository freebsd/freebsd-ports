--- xfumed/xfumed.c.orig	Wed Nov  7 13:09:02 2001
+++ xfumed/xfumed.c	Sat Mar  2 02:48:53 2002
@@ -163,7 +163,6 @@
 	g_error ("xfumed: Couldn't open file %s\n", filename);
     }
 
-  g_free (home);
   g_free (filename);
 
   if (xfmenu->ctree)
@@ -476,7 +475,6 @@
 
   home = g_getenv ("HOME");
   filename = g_strconcat (home, "/", RCFILE, NULL);
-  g_free (home);
   backup = g_strconcat (filename, ".bak", NULL);
 
   if ((backup_fp = fopen (backup, "w")) && (fp = fopen (filename, "r")))
