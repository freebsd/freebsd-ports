--- rep-gtk.h.orig	Thu Mar 18 16:17:18 2004
+++ rep-gtk.h	Thu Mar 18 16:17:29 2004
@@ -291,10 +291,10 @@
 
 GtkWidget*
 gtk_radio_menu_item_new_with_label_from_widget (GtkRadioMenuItem *group,
-						gchar            *label);
+						const gchar            *label);
 GtkWidget*
 gtk_radio_menu_item_new_with_mnemonic_from_widget (GtkRadioMenuItem *group,
-						   gchar            *label);
+						   const gchar            *label);
 GtkWidget* gtk_radio_menu_item_new_from_widget (GtkRadioMenuItem *group);
 GtkWidget* gtk_pixmap_new_interp (char *file, GtkWidget *intended_parent);
 
