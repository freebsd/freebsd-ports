--- src/gcursor.c.orig	Fri Mar 26 17:51:58 2004
+++ src/gcursor.c	Fri Mar 26 17:55:16 2004
@@ -16,7 +16,7 @@
 GConfClient *client;
 XcursorImage * cursor = NULL;
 char*current_theme = NULL;
-int path_index = 4;
+int path_index = 2;
 
 typedef struct {
 	XcursorImages *image;
@@ -26,9 +26,7 @@
 animation_struct animations[4];
 
 char *paths[4] = {
-	"/usr/share/cursors/xfree/",
-	"/usr/local/share/icons/",
-	"/usr/share/icons/",
+	"%%X11BASE%%/lib/X11/icons/",
 	"%s/.icons/"
 };	
 
