--- applets/notification_area/eggtraymanager.c.orig	Sat Dec 31 14:39:09 2005
+++ applets/notification_area/eggtraymanager.c	Mon May 15 01:36:18 2006
@@ -291,6 +291,36 @@
   return FALSE;
 }
 
+static gboolean
+transparent_expose_event (GtkWidget *widget, GdkEventExpose *event, gpointer user_data)
+{
+  gdk_window_clear_area (widget->window, event->area.x, event->area.y,
+			 event->area.width, event->area.height);
+  return FALSE;
+}
+
+static void
+make_transparent_again (GtkWidget *widget, GtkStyle *previous_style,
+			gpointer user_data)
+{
+  gdk_window_set_back_pixmap (widget->window, NULL, TRUE);
+}
+
+static void
+make_transparent (GtkWidget *widget, gpointer user_data)
+{
+  if (GTK_WIDGET_NO_WINDOW (widget) || GTK_WIDGET_APP_PAINTABLE (widget))
+    return;
+
+  gtk_widget_set_app_paintable (widget, TRUE);
+  gtk_widget_set_double_buffered (widget, FALSE);
+  gdk_window_set_back_pixmap (widget->window, NULL, TRUE);
+  g_signal_connect (widget, "expose_event",
+		    G_CALLBACK (transparent_expose_event), NULL);
+  g_signal_connect_after (widget, "style_set",
+			  G_CALLBACK (make_transparent_again), NULL);
+}
+
 static void
 egg_tray_manager_handle_dock_request (EggTrayManager       *manager,
 				      XClientMessageEvent  *xevent)
@@ -306,6 +336,8 @@
     }
   
   socket = gtk_socket_new ();
+  g_signal_connect (socket, "realize",
+		    G_CALLBACK (make_transparent), NULL);
   
   /* We need to set the child window here
    * so that the client can call _get functions
