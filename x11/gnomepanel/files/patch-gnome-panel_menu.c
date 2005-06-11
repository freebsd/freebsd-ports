--- gnome-panel/menu.c.orig	Sat Mar 26 15:12:10 2005
+++ gnome-panel/menu.c	Fri Jun  3 11:17:45 2005
@@ -1535,8 +1535,8 @@
 	return NULL;
 }
 
-static void
-image_menu_shown (GtkWidget *image, gpointer data)
+static gboolean
+image_menu_exposed (GtkWidget *image, GdkEventExpose *event, gpointer data)
 {
 	IconToLoad *new_icon;
 	IconToLoad *icon;
@@ -1545,7 +1545,7 @@
 
 	/* if we've already handled this */
 	if (gtk_image_get_storage_type (GTK_IMAGE (image)) != GTK_IMAGE_EMPTY)
-		return;
+		return FALSE;	/* propagate event */
 
 	if (find_in_load_list (image) == NULL) {
 		new_icon = icon_to_load_copy (icon);
@@ -1554,6 +1554,8 @@
 	}
 	if (load_icons_id == 0)
 		load_icons_id = g_idle_add (load_icons_handler, NULL);
+
+	return FALSE;		/* propagate event */
 }
 
 static void
@@ -1601,8 +1603,8 @@
 		gtk_image_menu_item_set_image (
 			GTK_IMAGE_MENU_ITEM (image_menu_item), image);
 
-	g_signal_connect_data (image, "map",
-			       G_CALLBACK (image_menu_shown), icon,
+	g_signal_connect_data (image, "expose-event",
+			       G_CALLBACK (image_menu_exposed), icon,
 			       (GClosureNotify) icon_to_load_free, 0);
 
 	g_signal_connect (image, "destroy",
