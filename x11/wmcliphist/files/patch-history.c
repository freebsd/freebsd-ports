--- history.c.orig	Sun Aug 24 16:59:37 2003
+++ history.c	Mon Dec 20 12:33:42 2004
@@ -1,3 +1,5 @@
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <wmcliphist.h>
 
 
@@ -182,7 +184,7 @@
 history_load()
 {
 	gchar		*buf;
-	gint		len;
+	size_t		len;
 	gint		ver;
 	FILE		*f;
 	gchar		*fname;
@@ -214,7 +216,7 @@
 	
 	while (!feof(f)) {
 
-		if (fread(&len, sizeof(gint), 1, f) != 1)
+		if (fread(&len, sizeof(size_t), 1, f) != 1)
 			break;
 
 		if (num_items == num_items_to_keep) {
@@ -299,7 +301,7 @@
 	list_node = g_list_last(history_items);
 	while (list_node) {
 		hist_item = (HISTORY_ITEM *)list_node->data;
-		if (fwrite(&hist_item->content_len, sizeof(gint), 1, f) != 1) {
+		if (fwrite(&hist_item->content_len, sizeof(size_t), 1, f) != 1) {
 			tmp_errno = E_WRITE;
 			break;
 		}
