--- examples/tree/tlstool.c.orig	1993-10-25 16:41:38.000000000 -0700
+++ examples/tree/tlstool.c	2013-09-17 08:46:29.022495738 -0700
@@ -346,7 +346,7 @@
 	new_path = (char*) xv_get(item, PANEL_VALUE);
 
 	if((!new_path) || (!*new_path))
-		return;
+		return 0;
 
 	directory = strrchr(new_path, '/');
 
