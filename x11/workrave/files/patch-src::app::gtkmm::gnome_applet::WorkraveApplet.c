--- src/app/gtkmm/gnome_applet/WorkraveApplet.c.orig	Wed Aug  6 23:01:06 2003
+++ src/app/gtkmm/gnome_applet/WorkraveApplet.c	Fri Aug 29 18:24:11 2003
@@ -849,6 +849,7 @@
 {
   GdkPixbuf *pixbuf = NULL;
   GtkWidget *hbox = NULL;
+  GtkWidget *event_box = gtk_event_box_new();
   BonoboUIComponent *ui = NULL;
   
   // Create menus.
@@ -863,7 +864,6 @@
   bonobo_ui_component_add_listener(ui, "Quiet", mode_callback, NULL);
 
   // Eventbox
-  GtkWidget *event_box = gtk_event_box_new();
   applet_control->event_box = event_box;
   gtk_widget_set_events(event_box, gtk_widget_get_events(event_box) | GDK_BUTTON_PRESS_MASK);
   gtk_widget_show(GTK_WIDGET(event_box));
