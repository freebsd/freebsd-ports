--- gtk-compat.c.orig	Thu Mar 18 16:17:34 2004
+++ gtk-compat.c	Thu Mar 18 16:17:49 2004
@@ -64,7 +64,7 @@
 
 GtkWidget*
 gtk_radio_menu_item_new_with_label_from_widget (GtkRadioMenuItem *group,
-						gchar            *label)
+						const gchar            *label)
 {
   GSList *g = group? gtk_radio_menu_item_group (group) : NULL;
   return gtk_radio_menu_item_new_with_label (g, label);
@@ -72,7 +72,7 @@
 
 GtkWidget*
 gtk_radio_menu_item_new_with_mnemonic_from_widget (GtkRadioMenuItem *group,
-						   gchar            *label)
+						   const gchar            *label)
 {
   GSList *g = group? gtk_radio_menu_item_group (group) : NULL;
   return gtk_radio_menu_item_new_with_mnemonic (g, label);
