--- font_sel.c.orig	Sat Feb  7 04:50:09 2004
+++ font_sel.c	Wed Jun 23 11:57:33 2004
@@ -27,17 +27,19 @@
 
 static void font_browse_clicked(GtkWidget *widget, gpointer u)
 {
+	const gchar *curfont;
+	gboolean is_confirmed = FALSE;
+
 	GtkFontSelectionDialog *font_dlg =
 		GTK_FONT_SELECTION_DIALOG(gtk_font_selection_dialog_new("Select Font"));
 
 	gtk_font_selection_dialog_set_preview_text(font_dlg, PROJNAME);
 
-	const gchar *curfont = gtk_entry_get_text(GTK_ENTRY(font_entry));
+	curfont = gtk_entry_get_text(GTK_ENTRY(font_entry));
 
 	if (g_utf8_strlen(curfont, -1))
 		gtk_font_selection_dialog_set_font_name(font_dlg, curfont);
 
-	gboolean is_confirmed = FALSE;
 
 	g_signal_connect(G_OBJECT(font_dlg->ok_button), "clicked",
 		G_CALLBACK(font_dlg_ok_clicked), &is_confirmed);
