--- src/gcursor.c.orig	Fri Mar 26 12:54:55 2004
+++ src/gcursor.c	Mon Apr  5 13:21:52 2004
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
 
@@ -348,7 +346,7 @@
 				GTK_STOCK_DIALOG_QUESTION, GTK_ICON_SIZE_LARGE_TOOLBAR);
 	}
 
-	if(animations[1].image->images != NULL && animations[1].image->nimage != 0)
+	if(animations[1].image != NULL && animations[1].image->nimage != 0)
 	{
 		pixbuf = get_pixbuf_from_cursor_image(animations[1].image->images[animations[1].pos]);
 		gtk_image_set_from_pixbuf(GTK_IMAGE(glade_xml_get_widget(main_window, "example_2")),
