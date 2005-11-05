--- battstat/battstat_applet.c.orig	Fri Aug 19 22:13:49 2005
+++ battstat/battstat_applet.c	Tue Aug 23 20:37:13 2005
@@ -430,14 +430,14 @@ battery_full_notify (GtkWidget *applet)
 static void
 battery_full_dialog (GtkWidget *applet)
 {
-  /* first attempt to use libnotify */
-  if (battery_full_notify (applet))
-	  return;
-  
   GtkWidget *dialog, *hbox, *image, *label;
   GdkPixbuf *pixbuf;
 
   gchar *new_label;
+  /* first attempt to use libnotify */
+  if (battery_full_notify (applet))
+	  return;
+  
   dialog = gtk_dialog_new_with_buttons (
 		_("Battery Notice"),
 		NULL,
