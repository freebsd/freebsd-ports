--- theme_sel.c.orig	2004-02-09 02:20:28 UTC
+++ theme_sel.c
@@ -53,6 +53,9 @@ static void insert_key_in_liststore(gcha
 
 GtkWidget *create_theme_sel(void)
 {
+	GtkTreeSelection *selection;
+	GtkTreeViewColumn *column;
+	GtkWidget *sw;
 	GtkListStore *store = gtk_list_store_new(1, G_TYPE_STRING);
 
 	gtk_tree_sortable_set_sort_column_id(GTK_TREE_SORTABLE(store), 0,
@@ -65,7 +68,7 @@ GtkWidget *create_theme_sel(void)
 	gtk_tree_view_set_rules_hint(GTK_TREE_VIEW(theme_list), TRUE);
 	gtk_tree_view_set_search_column(GTK_TREE_VIEW(theme_list), 0);
 
-	GtkTreeSelection *selection =
+	selection =
 		gtk_tree_view_get_selection(GTK_TREE_VIEW(theme_list));
 
 	gtk_tree_selection_set_mode(selection, GTK_SELECTION_BROWSE);
@@ -81,11 +84,12 @@ GtkWidget *create_theme_sel(void)
 
 		do
 		{
+			GtkTreePath *p;
 			gtk_tree_model_get(GTK_TREE_MODEL(store), &iter, 0, &newtheme, -1);
 			if (strcmp(newtheme, get_theme()) != 0)
 				continue;
 
-			GtkTreePath *p = gtk_tree_model_get_path(GTK_TREE_MODEL(store), &iter);
+			p = gtk_tree_model_get_path(GTK_TREE_MODEL(store), &iter);
 
 			gtk_tree_view_set_cursor(GTK_TREE_VIEW(theme_list), p, NULL, FALSE);
 			gtk_tree_view_scroll_to_cell(GTK_TREE_VIEW(theme_list), p, NULL, TRUE, 0.5, 0);
@@ -97,14 +101,14 @@ GtkWidget *create_theme_sel(void)
 
 	g_object_unref(G_OBJECT(store));
 
-	GtkTreeViewColumn *column =
+	column =
 		gtk_tree_view_column_new_with_attributes("Theme",
 		gtk_cell_renderer_text_new(), "text", 0, NULL);
 
 	gtk_tree_view_column_set_sort_column_id(column, 0);
 	gtk_tree_view_append_column(GTK_TREE_VIEW(theme_list), column);
 
-	GtkWidget *sw = gtk_scrolled_window_new(NULL, NULL);
+	sw = gtk_scrolled_window_new(NULL, NULL);
 
 	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(sw),
 		GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
