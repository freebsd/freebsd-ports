--- src/yelp-info.c.orig	Mon May 20 17:53:50 2002
+++ src/yelp-info.c	Mon May 20 17:54:27 2002
@@ -105,7 +105,6 @@
 	struct stat   stat_dir2;
 	GSList       *info_list = NULL;
 	GSList       *node;
-	YelpSection  *section;
 	gchar       **infopathes;
 	gchar        *infopath;
 	gint          i;
@@ -141,7 +140,7 @@
 
 	for (node = info_list; node; node = node->next) {
 		g_node_append_data (root, node->data);
-		*index = g_list_prepend (*index, section);
+		*index = g_list_prepend (*index, node->data);
 	}
 
 	g_slist_free (info_list);
