--- xfumed/xfumed.c.orig	Wed Nov  7 13:09:02 2001
+++ xfumed/xfumed.c	Sat Mar  2 02:32:50 2002
@@ -163,7 +163,6 @@
 	g_error ("xfumed: Couldn't open file %s\n", filename);
     }
 
-  g_free (home);
   g_free (filename);
 
   if (xfmenu->ctree)
