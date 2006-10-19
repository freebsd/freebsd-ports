===================================================================
RCS file: /cvs/gnome/gdm2/gui/greeter/greeter_item_ulist.c,v
retrieving revision 1.29
retrieving revision 1.30
diff -u -r1.29 -r1.30
--- gui/greeter/greeter_item_ulist.c	2006/05/31 09:24:08	1.29
+++ gui/greeter/greeter_item_ulist.c	2006/10/09 15:30:31	1.30
@@ -66,8 +66,10 @@
 greeter_item_ulist_unset_selected_user (void)
 {
 	GtkTreeSelection *selection;
-	selection = gtk_tree_view_get_selection (GTK_TREE_VIEW (user_list));
-	gtk_tree_selection_unselect_all (selection);
+	if (user_list != NULL) {
+		selection = gtk_tree_view_get_selection (GTK_TREE_VIEW (user_list));
+		gtk_tree_selection_unselect_all (GTK_TREE_SELECTION (selection));
+	}
 
 	if (selected_user != NULL)
 		g_free (selected_user);
