--- gnome-panel/panel.c.orig	Fri Aug  1 21:48:35 2003
+++ gnome-panel/panel.c	Fri Aug  1 21:48:37 2003
@@ -569,18 +569,18 @@
 
 	if (pd->menu)
 		g_object_unref (pd->menu);
-	pd->menu = NULL;
-
-	pd->panel = NULL;
 
 	if (pd->deactivate_idle != 0)
 		g_source_remove (pd->deactivate_idle);
-	pd->deactivate_idle = 0;
 
 	g_object_set_data (G_OBJECT (widget), "PanelData", NULL);
 
 	panel_list = g_slist_remove (panel_list, pd);
 	g_free (pd);
+
+	pd->menu = NULL;
+	pd->panel = NULL;
+	pd->deactivate_idle = 0;
 }
 
 static void
