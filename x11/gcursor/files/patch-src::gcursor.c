--- src/gcursor.c.orig	Thu Apr  8 10:25:03 2004
+++ src/gcursor.c	Thu Apr  8 18:00:14 2004
@@ -32,10 +32,7 @@
 
 #warning move this into gconf
 char *paths[] = {
-	"/usr/share/cursors/xfree/",
-	"/usr/X11R6/lib/X11/icons/",
-	"/usr/local/share/icons/",
-	"/usr/share/icons/",
+	"%%X11BASE%%/lib/X11/icons/",
 	"%s/.icons/",
 	NULL
 };	
