--- src/callbacks.c.orig	Tue Aug 27 15:30:54 2002
+++ src/callbacks.c	Tue Aug 27 15:30:36 2002
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
