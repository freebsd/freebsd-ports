--- src/ml_gtk.c.orig	2024-02-06 14:32:07 UTC
+++ src/ml_gtk.c
@@ -233,7 +233,7 @@ CAMLprim value ml_gtk_style_context_list_classes(value
 ML_2 (gtk_style_context_remove_class, GtkStyleContext_val, String_val, Unit)
 ML_2 (gtk_style_context_has_class, GtkStyleContext_val, String_val, Val_bool)
 CAMLprim value ml_gtk_style_context_list_classes(value ctx)
-{ return Val_GList(gtk_style_context_list_classes(GtkStyleContext_val(ctx)), Val_string); }
+{ return Val_GList(gtk_style_context_list_classes(GtkStyleContext_val(ctx)), (value_in)Val_string); }
 
 /* gtkdata.h */
 
