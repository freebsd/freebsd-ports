--- src/gcursor.c.orig	Tue Feb 24 04:49:10 2004
+++ src/gcursor.c	Tue Mar 23 23:30:06 2004
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
+	"/usr/X11R6/lib/X11/icons/",
 	"%s/.icons/"
 };	
 
@@ -177,8 +175,9 @@
 	/* where gnome 2.5(.5) uses a gconf key */
 #ifdef GNOME_VERSION_2_4
 	char *filepath;
+	FILE *fp;
 	filepath = g_strdup_printf("%s/.icons/default/index.theme", g_getenv("HOME"));
-	FILE *fp = fopen(filepath, "w");
+	fp = fopen(filepath, "w");
 	if(fp != NULL)
 	{
 		fprintf(fp, "[Icon Theme]\nInherits=%s\n", name);
@@ -251,9 +250,10 @@
 	int i = path_index;
 	while(i > 0)
 	{
-		dirname = g_strdup_printf(paths[i-1], g_getenv("HOME"));
-		GDir *directory = g_dir_open(dirname, 0, NULL);
+		GDir *directory;
 		const gchar *name = NULL;
+		dirname = g_strdup_printf(paths[i-1], g_getenv("HOME"));
+		directory = g_dir_open(dirname, 0, NULL);
 		while(directory != NULL && (name = g_dir_read_name(directory)) != NULL)		
 		{
 			GdkPixbuf *pixbuf;
