--- util.c.orig	Wed Jun 23 11:31:52 2004
+++ util.c	Wed Jun 23 11:32:20 2004
@@ -34,10 +34,11 @@
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
