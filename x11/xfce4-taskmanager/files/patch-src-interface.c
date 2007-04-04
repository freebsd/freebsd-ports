--- src/interface.c.orig	Wed Aug 23 20:55:38 2006
+++ src/interface.c	Thu Mar  1 16:20:58 2007
@@ -359,12 +359,9 @@
 
 gint compare_int_list_item(GtkTreeModel *model, GtkTreeIter *iter1, GtkTreeIter *iter2, gpointer column)
 {	
-	gchar *s1 = NULL;
-	gchar *s2 = NULL;
-	
-        s1 = (gchar*)malloc(sizeof(char) * 100);
-	s2 = (gchar*)malloc(sizeof(char) * 100);
-        
+ 	gchar s1[256];
+	gchar s2[256];      
+
 	gint ret = 0;
 
 	gtk_tree_model_get(model, iter1, column, &s1, -1);
@@ -380,40 +377,19 @@
 		i2 = atoi(s2);
 		
 	ret = i1 - i2;
-	
-	if(s1 != NULL)
-		g_free(s1);
-	if(s2 != NULL)
-		g_free(s2);
-	
 	return ret;
 }
 
 gint compare_string_list_item(GtkTreeModel *model, GtkTreeIter *iter1, GtkTreeIter *iter2, gpointer column)
 {	
-	gchar *s1 = NULL;
-	gchar *s2 = NULL;
-	
-        s1 = (gchar*)malloc(sizeof(gchar) * 100);
-	s2 = (gchar*)malloc(sizeof(gchar) * 100);
-        
+	gchar s1[256];
+	gchar s2[256];
+       
 	gint ret = 0;
 
 	gtk_tree_model_get(model, iter1, GPOINTER_TO_INT(column), &s1, -1);
 	gtk_tree_model_get(model, iter2, GPOINTER_TO_INT(column), &s2, -1);
-
-	if(s1 == NULL)
-		s1 = "";
-	if(s2 == NULL)
-		s2 = "";
-
 	ret = strcmp(s1, s2);
-	
-	if(s1 != NULL)
-		g_free(s1);
-	if(s2 != NULL)
-		g_free(s2);
-	
 	return ret;
 }
 
