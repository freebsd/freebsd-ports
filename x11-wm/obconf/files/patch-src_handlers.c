Enable compilation with GCC 2.X.
author:  Volker Stolz

--- src/handlers.c.orig	Wed Mar 24 09:36:08 2004
+++ src/handlers.c	Wed Mar 24 09:36:16 2004
@@ -41,6 +41,10 @@
 
 void setup_behavior_tab()
 {
+  GtkWidget *winresist_l;
+  GtkWidget *edgeresist_l;
+  GtkSizeGroup *group2;
+
   GtkWidget *winresist  = glade_xml_get_widget(glade, "resist_window");
   GtkWidget *edgeresist = glade_xml_get_widget(glade, "resist_edge");
   GtkSizeGroup *group1  = gtk_size_group_new(GTK_SIZE_GROUP_HORIZONTAL);
@@ -48,9 +52,9 @@
   gtk_size_group_add_widget(group1, winresist);
   gtk_size_group_add_widget(group1, edgeresist);
 
-  GtkWidget *winresist_l  = glade_xml_get_widget(glade, "resist_window_label");
-  GtkWidget *edgeresist_l = glade_xml_get_widget(glade, "resist_edge_label");
-  GtkSizeGroup *group2    = gtk_size_group_new(GTK_SIZE_GROUP_HORIZONTAL);
+  winresist_l  = glade_xml_get_widget(glade, "resist_window_label");
+  edgeresist_l = glade_xml_get_widget(glade, "resist_edge_label");
+  group2    = gtk_size_group_new(GTK_SIZE_GROUP_HORIZONTAL);
 
   gtk_size_group_add_widget(group2, winresist_l);
   gtk_size_group_add_widget(group2, edgeresist_l);
@@ -58,6 +62,10 @@
 
 void setup_dock_tab()
 {
+    GtkWidget *posi_l;
+    GtkWidget *dir_l;
+    GtkSizeGroup *group2;
+
     GtkWidget *posi = glade_xml_get_widget(glade, "dock_position");
     GtkWidget *dir  = glade_xml_get_widget(glade, "dock_direction");
     GtkSizeGroup *group1 = gtk_size_group_new(GTK_SIZE_GROUP_HORIZONTAL);
@@ -65,9 +73,9 @@
     gtk_size_group_add_widget(group1, posi);
     gtk_size_group_add_widget(group1, dir);
 
-    GtkWidget *posi_l = glade_xml_get_widget(glade, "dock_position_label");
-    GtkWidget *dir_l  = glade_xml_get_widget(glade, "dock_direction_label");
-    GtkSizeGroup *group2 = gtk_size_group_new(GTK_SIZE_GROUP_HORIZONTAL);
+    posi_l = glade_xml_get_widget(glade, "dock_position_label");
+    dir_l  = glade_xml_get_widget(glade, "dock_direction_label");
+    group2 = gtk_size_group_new(GTK_SIZE_GROUP_HORIZONTAL);
 
     gtk_size_group_add_widget(group2, posi_l);
     gtk_size_group_add_widget(group2, dir_l);
@@ -979,15 +987,16 @@
                                          const gchar *new_text,
                                          gpointer data)
 {
-    if (mapping) return;
-
-    GtkTreePath *path = gtk_tree_path_new_from_string (path_string);
+    GtkTreePath *path;
     GtkTreeIter it;
     gchar *old_text;
     GList *lit;
     gint i;
     xmlNodePtr n, c;
 
+    if (mapping) return;
+
+    path = gtk_tree_path_new_from_string (path_string);
     gtk_tree_model_get_iter(GTK_TREE_MODEL(desktop_store), &it, path);
 
     gtk_tree_model_get(GTK_TREE_MODEL(desktop_store), &it, 0, &old_text, -1);
