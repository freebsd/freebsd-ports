--- src/gcursor.c.orig	Mon Mar  8 01:16:17 2004
+++ src/gcursor.c	Mon Mar  8 01:16:51 2004
@@ -15,7 +15,7 @@
 GConfClient *client;
 XcursorImage * cursor = NULL;
 char*current_theme = NULL;
-int path_index = 4;
+int path_index = 2;
 
 typedef struct {
 	XcursorImages *image;
@@ -25,9 +25,7 @@
 animation_struct animations[4];
 
 char *paths[4] = {
-	"/usr/share/cursors/xfree/",
-	"/usr/local/share/icons/",
-	"/usr/share/icons/",
+	"%%X11BASE%%/lib/X11/icons/",
 	"%s/.icons/"
 };	
 
