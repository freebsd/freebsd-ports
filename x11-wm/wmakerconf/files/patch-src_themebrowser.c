--- src/themebrowser.c.orig	2007-04-12 10:38:44 UTC
+++ src/themebrowser.c
@@ -917,7 +917,7 @@ append_directory (const char *dirname, GtkCTree *tree,
       GtkCTreeNode *rootsibling = NULL;
 
       if (parent)
-	 root = append_node ((char *) g_basename (dirname), tree, parent,
+	 root = append_node ((char *) g_path_get_basename (dirname), tree, parent,
 			     sibling, NO);
       else
 	 root = append_node ((char *) dirname, tree, parent, sibling, NO);
@@ -2284,7 +2284,7 @@ leave_preview (GtkWidget *button, gpointer ptr)
 	      g_list_length (list) > 1
 	      ? _("Show next preview")
 	      : _("Leave preview mode"), NULL, leave_preview, list,
-	      _("Preview of `%s'"), g_basename (name));
+	      _("Preview of `%s'"), g_path_get_basename (name));
    }
 }
 
@@ -2705,7 +2705,7 @@ save_theme_backend (GtkWidget *widget, gpointer ptr)
 	 oldfiles = g_list_remove (oldfiles, tmp);
 	 Free (tmp);
       }
-      if (!WMWritePropListToFile (theme, stylename, YES))
+      if (!WMWritePropListToFile (theme, stylename))
       {
 	 dialog_popup (DIALOG_ERROR, NULL, NULL,
 		       _("Can't save theme file\n`%s'\n"
@@ -3526,17 +3526,17 @@ compute_preview (GtkWidget *progress_bar, GtkWidget *p
    path  = get_pixmap_path (pname);
 
    gtk_progress_bar_update (GTK_PROGRESS_BAR (progress_bar), n / (double) nelem);
-   gtk_label_set_text (GTK_LABEL (progress_label), g_basename (name));
+   gtk_label_set_text (GTK_LABEL (progress_label), g_path_get_basename (name));
    while (gtk_events_pending ())
       gtk_main_iteration ();
 
    if (!path)
    {
-      DIR *dir = opendir (g_dirname (pname));
+      DIR *dir = opendir (g_path_get_dirname (pname));
 
       if (!dir)				/* Make ~/.wmakerconf directory */
       {
-	 if (make_directory (g_dirname (pname)))
+	 if (make_directory (g_path_get_dirname (pname)))
 	 {
 	    Free (pname);
 	    return;
