--- src/bin/enity.c.orig	Thu Oct  5 01:06:18 2006
+++ src/bin/enity.c	Thu Oct  5 01:07:02 2006
@@ -376,7 +376,7 @@
 	     
 	     valist[j] = NULL;
 	     	     
-	     row = etk_tree_append_valist(ETK_TREE(tree), (va_list)valist);
+/*	     row = etk_tree_append_valist(ETK_TREE(tree), (va_list)valist); */
 	     etk_tree_row_data_set(row, cols);
 	  }
      }
@@ -583,7 +583,7 @@
      /* --list options */
      { "checklist", ' ', NULL, _en_list_check_cb, NULL, EN_ARGUMENT_FLAG_OPTIONAL, "Use check boxes for first column" },
      { "column", ' ', NULL, _en_list_column_cb, NULL, EN_ARGUMENT_FLAG_OPTIONAL|EN_ARGUMENT_FLAG_VALUE_REQUIRED|EN_ARGUMENT_FLAG_MULTIVALUE, "Set the column header" },
-     { "list", ' ', NULL, _en_list_cb, NULL, EN_ARGUMENT_FLAG_OPTIONAL, "Display list dialog" },
+/*     { "list", ' ', NULL, _en_list_cb, NULL, EN_ARGUMENT_FLAG_OPTIONAL, "Display list dialog" }, */
 
      /* --progress options */
      { "progress", ' ', NULL, _en_progress_cb, NULL, EN_ARGUMENT_FLAG_OPTIONAL, "Display progress indication dialog" },
