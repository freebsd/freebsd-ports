--- history.c.orig
+++ history.c
@@ -1,3 +1,5 @@
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <wmcliphist.h>
 
 
@@ -180,7 +182,7 @@
 history_load(gboolean dump_only)
 {
 	gchar		*buf;
-	gint		len;
+	size_t		len;
 	gint		ver;
 	FILE		*f;
 	gchar		*fname;
@@ -215,7 +217,7 @@
 	}
 	while (!feof(f)) {
 
-		if (fread(&len, sizeof(gint), 1, f) != 1)
+		if (fread(&len, sizeof(size_t), 1, f) != 1)
 			break;
 
 		if (num_items == num_items_to_keep && !dump_only) {
@@ -306,10 +308,10 @@
 
 	list_node = g_list_last(history_items);
 	while (list_node) {
-		int length;
+		size_t length;
 		hist_item = (HISTORY_ITEM *)list_node->data;
 		length = strlen(hist_item->content);
-		if (fwrite(&length, sizeof(gint), 1, f) != 1) {
+		if (fwrite(&length, sizeof(size_t), 1, f) != 1) {
 			tmp_errno = E_WRITE;
 			break;
 		}
