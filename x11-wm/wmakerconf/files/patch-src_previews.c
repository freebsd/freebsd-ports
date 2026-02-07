--- src/previews.c.orig	2004-12-07 00:37:10 UTC
+++ src/previews.c
@@ -326,7 +326,7 @@ make_preview (GtkWidget *entry, char *name)
       Free (pname);
    }
    
-   gtk_tooltips_set_tip (tooltips, data->button, g_basename (name), NULL);
+   gtk_tooltips_set_tip (tooltips, data->button, g_path_get_basename (name), NULL);
    gtk_container_set_border_width (GTK_CONTAINER (data->button), 2);
    gtk_container_add (GTK_CONTAINER (data->button), pixmap);
    gtk_widget_show_all (data->button);
@@ -344,7 +344,7 @@ set_selection (GtkWidget *widget, GdkEventButton *even
    GtkWidget	 *entry  = gtk_object_get_user_data (GTK_OBJECT (pixmap));
    previewdata_t *data   = (previewdata_t *) ptr;
 
-   gtk_entry_set_text (GTK_ENTRY (entry), g_basename (data->name));
+   gtk_entry_set_text (GTK_ENTRY (entry), g_path_get_basename (data->name));
 
    if (event->type == GDK_2BUTTON_PRESS)
      gtk_signal_emit_by_name (GTK_OBJECT (ok_button), "clicked");
