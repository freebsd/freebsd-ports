--- src/callbacks.c.original	Sat Oct 12 14:42:02 2002
+++ src/callbacks.c	Sat Oct 12 14:50:10 2002
@@ -35,7 +35,7 @@
 GtkWidget *treeview1_cheat;
 GtkWidget *install_dialog_cheat;
 GtkWidget *refresh_button_cheat;
-gchar *metacity_version = "2.3";
+gchar *metacity_version = "2.4";
 
 enum
 {
@@ -228,14 +228,25 @@
 
 			while ((filename =
 				g_dir_read_name (themeDirectory)) != NULL)
-				if (g_file_test
+				if ((g_file_test
 				    (g_build_filename
 				     (possibleThemeDirs[i], filename, NULL),
 						G_FILE_TEST_IS_DIR) &&
 					(g_file_test
 						(g_build_filename
 							(possibleThemeDirs[i], filename, "metacity-theme-1.xml", NULL),
-						G_FILE_TEST_IS_REGULAR)))
+						G_FILE_TEST_IS_REGULAR))) ||
+				   ((g_file_test
+				         (g_build_filename
+					  (possibleThemeDirs[i], filename, NULL),
+					  	G_FILE_TEST_IS_DIR) &&
+					    (g_file_test
+					            (g_build_filename
+						            (possibleThemeDirs[i], filename, "metacity-1", NULL), G_FILE_TEST_IS_DIR) &&
+							    (g_file_test
+							      (g_build_filename
+							        (possibleThemeDirs[i], filename, "metacity-1", "metacity-theme-1.xml", NULL), G_FILE_TEST_IS_REGULAR))))))
+
 					{
 						g_ptr_array_add (themeNameHolder,
 							 g_strdup (filename));
@@ -690,4 +701,4 @@
 	else 
 		metacity_version = "2.4";
 	on_treeview1_realize (treeview1_cheat, user_data);
-}
+}
