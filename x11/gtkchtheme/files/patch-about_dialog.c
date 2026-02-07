--- about_dialog.c.orig	2004-02-07 00:19:34 UTC
+++ about_dialog.c
@@ -37,21 +37,22 @@ Foundation, 59 Temple Place - Suite 330,
 
 void show_about_dialog(void) {
 	GtkWidget* about_dlg = gtk_dialog_new();
+	GtkWidget* about, *box, *ok_button;
 	gtk_window_set_title(GTK_WINDOW(about_dlg), "About");
 	gtk_window_set_resizable(GTK_WINDOW(about_dlg), FALSE);
 	gtk_dialog_set_has_separator(GTK_DIALOG(about_dlg), FALSE);
 	gtk_container_set_border_width(GTK_CONTAINER(GTK_DIALOG(about_dlg)->vbox), 20);
 	
-	GtkWidget* about = GTK_WIDGET(gtk_label_new_from_pango_markup((ABOUT), GTK_JUSTIFY_CENTER));
+	about = GTK_WIDGET(gtk_label_new_from_pango_markup((ABOUT), GTK_JUSTIFY_CENTER));
 
-	GtkWidget* box = gtk_hbox_new(FALSE, 0);
+	box = gtk_hbox_new(FALSE, 0);
 	gtk_container_set_border_width(GTK_CONTAINER(box), 20);
 	gtk_box_pack_start(GTK_BOX(box), about, FALSE, FALSE, 10);
 	gtk_widget_show_all(box);
 
 	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(about_dlg)->vbox), box, FALSE, FALSE, 10);
 
-	GtkWidget* ok_button = gtk_dialog_add_button(GTK_DIALOG(about_dlg), GTK_STOCK_OK, 0);
+	ok_button = gtk_dialog_add_button(GTK_DIALOG(about_dlg), GTK_STOCK_OK, 0);
 	gtk_button_set_use_stock(GTK_BUTTON(ok_button), TRUE);
 
 	gtk_dialog_run(GTK_DIALOG(about_dlg));
