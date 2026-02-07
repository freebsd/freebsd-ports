--- util.c.orig	2004-02-08 13:42:33 UTC
+++ util.c
@@ -34,10 +34,11 @@ GtkLabel* gtk_label_new_from_pango_marku
 {
 	PangoAttrList *attrs;
 	gchar* parsed_text;
+	GtkLabel* label;
 	
 	pango_parse_markup(markup_text, -1, 0, &attrs, &parsed_text, NULL, NULL);
 
-	GtkLabel* label = GTK_LABEL(gtk_label_new(parsed_text));
+	label = GTK_LABEL(gtk_label_new(parsed_text));
 	gtk_label_set_attributes(label, attrs);
 	gtk_label_set_line_wrap(label, TRUE);
 	gtk_label_set_justify(label, jtype);
