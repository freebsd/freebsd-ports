--- applets/notification_area/main.c.orig	Wed Dec 28 22:15:27 2005
+++ applets/notification_area/main.c	Mon May 15 01:36:01 2006
@@ -159,14 +159,24 @@
   tray = all_trays->data;
 
   gtk_box_pack_end (GTK_BOX (tray->box), icon, FALSE, FALSE, 0);
-  
+
+  gtk_widget_hide (tray->box);
   gtk_widget_show (icon);
+  gtk_widget_show (tray->box);
 }
 
 static void
 tray_removed (EggTrayManager *manager, GtkWidget *icon, void *data)
 {
+  SystemTray *tray;
+
+  if (all_trays == NULL)
+    return;
+  
+  tray = all_trays->data;
 
+  gtk_widget_hide (tray->box);
+  gtk_widget_show (tray->box);
 }
 
 static void
@@ -207,9 +217,32 @@
       gtk_widget_set_size_request (tray->box, -1, MIN_BOX_SIZE);
       break;
     }
+
+  /* Force the icons to redraw their backgrounds.
+   * gtk_widget_queue_draw() doesn't work across process boundaries,
+   * so we do this instead.
+   */
+  gtk_widget_hide (tray->box);
+  gtk_widget_show (tray->box);
 }
 
 static void
+applet_change_background (PanelApplet               *applet,
+                          PanelAppletBackgroundType  type,
+                          GdkColor                  *color,
+                          GdkPixmap                 *pixmap,
+			  SystemTray                *tray)
+{
+  /* Force the icons to redraw their backgrounds.
+   * gtk_widget_queue_draw() doesn't work across process boundaries,
+   * so we do this instead.
+   */
+  gtk_widget_hide (tray->box);
+  gtk_widget_show (tray->box);
+}
+
+
+static void
 applet_change_orientation (PanelApplet       *applet,
                            PanelAppletOrient  orient,
                            SystemTray        *tray)
@@ -332,6 +365,11 @@
   g_signal_connect (G_OBJECT (tray->applet),
                     "change_orient",
                     G_CALLBACK (applet_change_orientation),
+                    tray);
+
+  g_signal_connect (G_OBJECT (tray->applet),
+                    "change_background",
+                    G_CALLBACK (applet_change_background),
                     tray);
 
   g_signal_connect (tray->applet,
