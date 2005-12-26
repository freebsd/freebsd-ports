--- gnee/src/callbacks.c.orig	Thu Dec  8 08:43:13 2005
+++ gnee/src/callbacks.c	Wed Dec 21 23:02:55 2005
@@ -467,8 +467,8 @@
 {
   GtkWidget          *about_box;
   GtkWidget          *about_label_1;
-  GNEE_DEBUG(("on_about1_activate\n"));
   char buf[256];
+  GNEE_DEBUG(("on_about1_activate\n"));
 
   about_box      = lookup_widget(GTK_WIDGET(user_data),
 				 "about_window");
