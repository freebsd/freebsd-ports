--- src/gcursor.c.orig	Mon Sep 20 14:34:20 2004
+++ src/gcursor.c	Mon Sep 20 14:34:25 2004
@@ -32,29 +32,21 @@
 
 #warning move this into gconf
 char *paths[] = {
-	"/usr/share/cursors/xfree/",
-	"/usr/X11R6/lib/X11/icons/",
-	"/usr/Xorg/lib/X11/icons/",
-	"/usr/local/share/icons/",
-	"/usr/share/icons/",
+	"%%X11BASE%%/lib/X11/icons/",
 	"%s/.icons/",
 	NULL
 };	
 
 void open_theme_dir()
 {
-	GError	* error = NULL;
-	char	* filename;
-	
-	filename = g_strdup_printf("file:///%s/.icons/", g_getenv("HOME"));
-	gnome_url_show(filename,&error);
-	g_free(filename);
+	gchar *path, *command;
 
-	if (error)
-	{
-		gnome_warning_dialog (error->message);
-		g_error_free (error);
-	}
+	path = g_strdup_printf ("%s/.icons", g_get_home_dir());
+	command = g_strdup_printf ("nautilus --no-desktop %s", path);
+
+	g_free (path);
+	g_spawn_command_line_async (command, NULL);
+	g_free (command);
 }
 
 
@@ -85,7 +77,7 @@
 			filename = g_shell_quote(gtk_file_selection_get_filename(GTK_FILE_SELECTION(fs)));
 #endif
 
-		path = g_strdup_printf("file-roller --extract-to=%s/.icons/ %s", g_getenv("HOME"), 
+		path = g_strdup_printf("file-roller --extract-to=%s/.icons/ %s", g_get_home_dir(), 
 				filename);
 		g_free(filename);
 
@@ -281,7 +273,7 @@
 	
 	for (iterator = paths; *iterator; iterator++)
 	{
-		dirname = g_strdup_printf(*iterator, g_getenv("HOME"));
+		dirname = g_strdup_printf(*iterator, g_get_home_dir());
 		directory = g_dir_open(dirname, 0, NULL);
 		
 		while(directory != NULL && (name = g_dir_read_name(directory)) != NULL)		
