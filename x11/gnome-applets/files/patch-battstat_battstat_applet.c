--- battstat/battstat_applet.c.orig	2010-11-22 15:38:27.000000000 +0100
+++ battstat/battstat_applet.c	2011-03-07 19:09:55.000000000 +0100
@@ -435,7 +435,7 @@ battery_full_notify (GtkWidget *applet)
 			GTK_ICON_LOOKUP_USE_BUILTIN,
 			NULL);
 	
-	NotifyNotification *n = notify_notification_new (_("Your battery is now fully recharged"), "", /* "battery" */ NULL, applet);
+	NotifyNotification *n = notify_notification_new (_("Your battery is now fully recharged"), "", /* "battery" */ NULL);
 
 	/* XXX: it would be nice to pass this as a named icon */
 	notify_notification_set_icon_from_pixbuf (n, icon);
@@ -462,14 +462,14 @@ battery_full_notify (GtkWidget *applet)
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
