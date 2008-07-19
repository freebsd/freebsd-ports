--- src/configurator.c.orig	2008-07-17 14:36:27.000000000 +0800
+++ src/configurator.c	2008-07-17 14:38:36.000000000 +0800
@@ -46,6 +46,7 @@
 void restart(void);
 void gtk_run(void);
 void panel_config_save(Panel* panel);
+void save_global_config(void);
 static void logout(void);
 
 Command commands[] = {
@@ -532,7 +533,7 @@
     gtk_box_pack_start( (GtkBox*)GTK_DIALOG(dlg)->vbox, scroll,
                          TRUE, TRUE, 4 );
     view = (GtkTreeView*)gtk_tree_view_new();
-    gtk_container_add( (GtkContainer*)scroll, view );
+    gtk_container_add( (GtkContainer*)scroll, (GtkWidget*)view );
     tree_sel = gtk_tree_view_get_selection( view );
     gtk_tree_selection_set_mode( tree_sel, GTK_SELECTION_BROWSE );
 
