--- gui/gnome/WorkraveApplet.c.orig	Tue Mar 18 22:04:42 2003
+++ gui/gnome/WorkraveApplet.c	Thu Jul 31 13:43:50 2003
@@ -783,6 +783,7 @@
 {
   GdkPixbuf *pixbuf = NULL;
   GtkWidget *hbox = NULL;
+  GtkWidget *event_box = gtk_event_box_new();
   BonoboUIComponent *ui = NULL;
   
   // Create menus.
@@ -797,7 +798,7 @@
   bonobo_ui_component_add_listener(ui, "Quiet", mode_callback, NULL);
 
   // Eventbox
-  GtkWidget *event_box = gtk_event_box_new();
+//  GtkWidget *event_box = gtk_event_box_new();
   applet_control->event_box = event_box;
   gtk_widget_set_events(event_box, gtk_widget_get_events(event_box) | GDK_BUTTON_PRESS_MASK);
   gtk_widget_show(GTK_WIDGET(event_box));
