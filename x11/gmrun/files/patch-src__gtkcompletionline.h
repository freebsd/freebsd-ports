--- src/gtkcompletionline.h.orig	2003-11-16 10:43:32 UTC
+++ src/gtkcompletionline.h
@@ -76,7 +76,7 @@ extern "C++" {
     void (* cancel)(GtkCompletionLine *cl);
   };
 
-  guint gtk_completion_line_get_type(void);
+  GtkType gtk_completion_line_get_type(void);
   GtkWidget *gtk_completion_line_new();
 
   void gtk_completion_line_last_history_item(GtkCompletionLine*);
