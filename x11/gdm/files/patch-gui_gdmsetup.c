--- gui/gdmsetup.c.orig	Thu Jun 30 16:47:06 2005
+++ gui/gdmsetup.c	Mon Jul  4 02:53:12 2005
@@ -533,6 +533,7 @@ combobox_timeout (GtkWidget *combo_box)
 		GtkTreeIter iter;
 		GValue value  = {0, };
 		gboolean val = ve_config_get_bool (config, key);
+		gboolean GdmGraphicalThemeRand;
 		GtkWidget *theme_list = glade_helper_get (xml, "gg_theme_list",
 			GTK_TYPE_TREE_VIEW);
 		GtkWidget *del_button = glade_helper_get (xml, "gg_delete_theme",
@@ -565,7 +566,7 @@ combobox_timeout (GtkWidget *combo_box)
 		}
 
 		/* Update Delete Button's sensitivity */
-	    gboolean GdmGraphicalThemeRand = ve_config_get_bool (
+	    GdmGraphicalThemeRand = ve_config_get_bool (
     	    ve_config_get (GDM_CONFIG_FILE),
         	GDM_KEY_GRAPHICAL_THEME_RAND);
 		selection = gtk_tree_view_get_selection (GTK_TREE_VIEW (theme_list));
@@ -575,11 +576,11 @@ combobox_timeout (GtkWidget *combo_box)
 		{
 			gtk_widget_set_sensitive (del_button, FALSE);
 		} else {
+			GtkTreeModel *model;
 			/* Default to allow deleting of themes */
 			gtk_widget_set_sensitive (del_button, TRUE);
 
 			/* Determine if the theme selected is currently active */
-			GtkTreeModel *model;
 			model = gtk_tree_view_get_model (GTK_TREE_VIEW (theme_list));
 			if (GdmGraphicalThemeRand) {
 				gtk_tree_model_get_value (model, &iter,
@@ -3270,7 +3271,7 @@ theme_install_response (GtkWidget *choos
 		/* HACK! */
 		argv[0] = chown;
 		argv[1] = "-R";
-		argv[2] = "root:root";
+		argv[2] = "root:wheel";
 		argv[3] = quoted;
 		argv[4] = NULL;
 		simple_spawn_sync (argv);
@@ -4024,6 +4025,7 @@ setup_graphical_themes (void)
 	GtkTreeViewColumn *column;
 	GtkTreeSelection *selection;
 	GtkTreeIter *select_iter = NULL;
+	gboolean GdmGraphicalThemeRand;
 	GtkWidget *theme_list = glade_helper_get (xml, "gg_theme_list",
 						  GTK_TYPE_TREE_VIEW);
 	GtkWidget *button = glade_helper_get (xml, "gg_install_new_theme",
@@ -4050,7 +4052,7 @@ setup_graphical_themes (void)
 		  slash (/) character in them, so I just made GDM_DELIMITER_THEMES
 		  equal to "/:" instead. */
 
-	gboolean GdmGraphicalThemeRand = ve_config_get_bool (
+	GdmGraphicalThemeRand = ve_config_get_bool (
 		ve_config_get (GDM_CONFIG_FILE),
 		GDM_KEY_GRAPHICAL_THEME_RAND);
 
