--- src/gui.c.orig	Tue Feb  1 23:20:47 2005
+++ src/gui.c	Tue May 24 21:51:04 2005
@@ -98,24 +98,25 @@
 gboolean add_new_list_item(struct task task)
 {
 	GtkTreeIter iter;
+	gchar *list_value_1, *list_value_2, *list_value_3, *list_value_4;
 	
 	/* Append new line in the list */
 	gtk_list_store_append(GTK_LIST_STORE(list_store), &iter);
 	
 	/* Fill the appended line with data */
-	gchar *list_value_1 = g_strdup_printf("%s", task.uid);
+	list_value_1 = g_strdup_printf("%s", task.uid);
 	gtk_list_store_set(GTK_LIST_STORE(list_store), &iter, 0, list_value_1, -1);
 	g_free(list_value_1);
 
-	gchar *list_value_2 = g_strdup_printf("%s", task.pid);
+	list_value_2 = g_strdup_printf("%s", task.pid);
 	gtk_list_store_set(GTK_LIST_STORE(list_store), &iter, 1, list_value_2, -1);
 	g_free(list_value_2);
 	
-	gchar *list_value_3 = g_strdup_printf("%s", task.ppid);
+	list_value_3 = g_strdup_printf("%s", task.ppid);
 	gtk_list_store_set(GTK_LIST_STORE(list_store), &iter, 2, list_value_3, -1);
 	g_free(list_value_3);
 	
-	gchar *list_value_4 = g_strdup_printf("%s", task.name);
+	list_value_4 = g_strdup_printf("%s", task.name);
 	gtk_list_store_set(GTK_LIST_STORE(list_store), &iter, 3, list_value_4, -1);
 	g_free(list_value_4);
 	
