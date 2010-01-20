--- ./src/gtkcompletionline.h.orig	2003-11-16 13:43:32.000000000 +0300
+++ ./src/gtkcompletionline.h	2010-01-20 21:24:57.489100621 +0300
@@ -76,7 +76,7 @@
     void (* cancel)(GtkCompletionLine *cl);
   };
 
-  guint gtk_completion_line_get_type(void);
+  GtkType gtk_completion_line_get_type(void);
   GtkWidget *gtk_completion_line_new();
 
   void gtk_completion_line_last_history_item(GtkCompletionLine*);
