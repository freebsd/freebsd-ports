--- src/bin/enity.c.orig	Thu Mar 15 09:55:46 2007
+++ src/bin/enity.c	Thu Mar 15 09:57:47 2007
@@ -378,7 +378,9 @@
 	     
 	     valist[j] = NULL;
 	     	     
+/*
 	     row = etk_tree_row_append(ETK_TREE(tree), NULL, (va_list)valist);
+*/
 	     etk_tree_row_data_set(row, cols);
 	  }
      }
@@ -585,7 +587,7 @@
      /* --list options */
      { "checklist", ' ', NULL, _en_list_check_cb, NULL, EN_ARGUMENT_FLAG_OPTIONAL, "Use check boxes for first column" },
      { "column", ' ', NULL, _en_list_column_cb, NULL, EN_ARGUMENT_FLAG_OPTIONAL|EN_ARGUMENT_FLAG_VALUE_REQUIRED|EN_ARGUMENT_FLAG_MULTIVALUE, "Set the column header" },
-     { "list", ' ', NULL, _en_list_cb, NULL, EN_ARGUMENT_FLAG_OPTIONAL, "Display list dialog" },
+/*     { "list", ' ', NULL, _en_list_cb, NULL, EN_ARGUMENT_FLAG_OPTIONAL, "Display list dialog" }, */
 
      /* --progress options */
      { "progress", ' ', NULL, _en_progress_cb, NULL, EN_ARGUMENT_FLAG_OPTIONAL, "Display progress indication dialog" },
