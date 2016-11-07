--- mainwin.c.orig	2004-02-08 13:28:55 UTC
+++ mainwin.c
@@ -42,6 +42,7 @@ static void ok_clicked(GtkWidget *widget
 GtkWidget* create_mainwin(void)
 {
 	GtkWidget *mainwin = gtk_dialog_new();
+	GtkWidget *about_button, *apply_button, *ok_button, *cancel_button;
 	gtk_widget_realize(mainwin);
 	gtk_window_set_title(GTK_WINDOW(mainwin), PROJNAME);
 	gtk_window_set_resizable(GTK_WINDOW(mainwin), TRUE);
@@ -54,21 +55,21 @@ GtkWidget* create_mainwin(void)
 	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(mainwin)->vbox), gtk_hseparator_new(), FALSE, FALSE, 0);
 	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(mainwin)->vbox), create_font_sel(), FALSE, FALSE, 0);
 
-	GtkWidget* about_button = gtk_button_new_from_stock(GTK_STOCK_ABOUT);
+	about_button = gtk_button_new_from_stock(GTK_STOCK_ABOUT);
 	g_signal_connect(G_OBJECT(about_button), "clicked", G_CALLBACK(about_clicked), NULL);
 	gtk_box_pack_end(GTK_BOX(GTK_DIALOG(mainwin)->action_area), about_button, TRUE, TRUE, 0);
 
-	GtkWidget* apply_button = gtk_button_new_from_stock(GTK_STOCK_APPLY);
+	apply_button = gtk_button_new_from_stock(GTK_STOCK_APPLY);
 	g_signal_connect(G_OBJECT(apply_button), "clicked", G_CALLBACK(apply_clicked), NULL);
 	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(mainwin)->action_area), apply_button, TRUE, TRUE, 0);
 	await_activation(apply_button);
 
-	GtkWidget* ok_button = gtk_button_new_from_stock(GTK_STOCK_OK);
+	ok_button = gtk_button_new_from_stock(GTK_STOCK_OK);
 	g_signal_connect(G_OBJECT(ok_button), "clicked", G_CALLBACK(ok_clicked), NULL);
 	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(mainwin)->action_area), ok_button, TRUE, TRUE, 0);
 	await_activation(ok_button);
 
-	GtkWidget *cancel_button = gtk_button_new_from_stock(GTK_STOCK_CANCEL);
+	cancel_button = gtk_button_new_from_stock(GTK_STOCK_CANCEL);
 	g_signal_connect(G_OBJECT(cancel_button), "clicked", G_CALLBACK(gtk_main_quit), NULL);
 	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(mainwin)->action_area), cancel_button, TRUE, TRUE, 0);
 
