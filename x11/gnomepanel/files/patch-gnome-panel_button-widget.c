--- gnome-panel/button-widget.c.orig	Sat Sep 20 14:16:37 2003
+++ gnome-panel/button-widget.c	Sat Sep 20 14:16:39 2003
@@ -37,68 +37,6 @@
 
 static GObjectClass *parent_class;
 
-static void
-translate_to(GtkWidget *from, GtkWidget *to, int *x, int *y)
-{
-	while (from != to) {
-		if (!GTK_WIDGET_NO_WINDOW (from)) {
-			*x += MAX (from->allocation.x, 0);
-			*y += MAX (from->allocation.y, 0);
-		}
-		from = from->parent;
-	}
-}
-
-static void
-calculate_overlay_geometry (PanelWidget *panel,
-			    GtkWidget   *parent,
-			    GtkWidget   *applet,
-			    int         *x,
-			    int         *y,
-			    int         *w,
-			    int         *h)
-{
-	*x = applet->allocation.x;
-	*y = applet->allocation.y;
-	*w = applet->allocation.width;
-	*h = applet->allocation.height;
-
-	translate_to (GTK_WIDGET(panel), parent, x, y);
-
-	if(panel->orient == GTK_ORIENTATION_HORIZONTAL) {
-		if (applet->allocation.x > panel->size) {
-			*x = parent->requisition.width + 1;
-			*y = parent->requisition.height + 1;
-			return;
-		}
-
-		*y = 0;
-		/* we use the requisition, since allocation might have not
-		   yet happened if we are inside the allocation, anyway
-		   they are the same for basep */
-		if(*h < parent->requisition.height)
-			*h = parent->requisition.height;
-
-		if ((*w + applet->allocation.x) > panel->size) {
-			*w = panel->size - applet->allocation.x;
-		}
-	} else {
-		if (applet->allocation.y > panel->size) {
-			*x = parent->requisition.width + 1;
-			*y = parent->requisition.height + 1;
-			return;
-		}
-
-		*x = 0;
-		if(*w < parent->requisition.width)
-			*w = parent->requisition.width;
-
-		if ((*h + applet->allocation.y) > panel->size) {
-			*h = panel->size - applet->allocation.y;
-		}
-	}
-}
-
 /* colorshift a pixbuf */
 static void
 do_colorshift (GdkPixbuf *dest, GdkPixbuf *src, int shift)
@@ -163,27 +101,19 @@
 	GdkWindowAttr attributes;
 	gint attributes_mask;
 	GtkButton *button;
-	PanelWidget *panel;
-	GtkWidget *parent;
-	int x,y,w,h;
 
 	g_return_if_fail (widget != NULL);
 	g_return_if_fail (BUTTON_IS_WIDGET (widget));
 
-	panel  = PANEL_WIDGET(widget->parent);
-	parent = GTK_WIDGET (panel->toplevel);
-
-	calculate_overlay_geometry(panel, parent, widget, &x, &y, &w, &h);
-
 	button = GTK_BUTTON (widget);
 
 	GTK_WIDGET_SET_FLAGS (widget, GTK_REALIZED);
 
 	attributes.window_type = GDK_WINDOW_CHILD;
-	attributes.x = x;
-	attributes.y = y;
-	attributes.width = w;
-	attributes.height = h;
+	attributes.x = widget->allocation.x;
+	attributes.y = widget->allocation.y;
+	attributes.width = widget->allocation.width;
+	attributes.height = widget->allocation.height;
 	attributes.wclass = GDK_INPUT_ONLY;
 	attributes.event_mask = (GDK_BUTTON_PRESS_MASK |
 				 GDK_BUTTON_RELEASE_MASK |
@@ -194,10 +124,10 @@
 				 GDK_LEAVE_NOTIFY_MASK);
 	attributes_mask = GDK_WA_X | GDK_WA_Y;
 
-	widget->window = gtk_widget_get_parent_window(widget);
+	widget->window = gtk_widget_get_parent_window (widget);
 	g_object_ref (G_OBJECT (widget->window));
       
-	button->event_window = gdk_window_new (parent->window,
+	button->event_window = gdk_window_new (gtk_widget_get_parent_window (widget),
 					       &attributes,
 					       attributes_mask);
 	gdk_window_set_user_data (button->event_window, widget);
@@ -206,24 +136,26 @@
 }
 
 static void
-button_widget_parent_set (GtkWidget *widget,
-			  GtkWidget *previous_parent)
+button_widget_unrealize (GtkWidget *widget)
 {
+	GtkButton *button;
+	PanelWidget *panel;
 	GtkWidget *parent;
-	int        x, y, w, h;
 
+	g_return_if_fail (widget != NULL);
 	g_return_if_fail (BUTTON_IS_WIDGET (widget));
 
-	if (!GTK_WIDGET_REALIZED (widget)|| !widget->parent)
-		return;
-
-	parent = GTK_WIDGET (PANEL_WIDGET (widget->parent)->toplevel);
+	panel = PANEL_WIDGET (widget->parent);
+	parent = GTK_WIDGET (panel->toplevel);
+	button = GTK_BUTTON (widget);
 
-	calculate_overlay_geometry (
-		PANEL_WIDGET (widget->parent), parent, widget, &x, &y, &w, &h);
+	if (button->event_window != NULL) {
+	    	gdk_window_set_user_data (button->event_window, NULL);
+		gdk_window_destroy (button->event_window);
+		button->event_window = NULL;
+	}
 
-	gdk_window_reparent (
-		GTK_BUTTON (widget)->event_window, parent->window, x, y);
+	GTK_WIDGET_CLASS (parent_class)->unrealize (widget);
 }
 
 static void
@@ -686,15 +618,15 @@
 
 	if (GTK_WIDGET_REALIZED (widget)) {
 		PanelWidget *panel;
-		int          x, y, w, h;
 
 		panel = PANEL_WIDGET (widget->parent);
 
-		calculate_overlay_geometry (
-			panel, GTK_WIDGET (panel->toplevel),
-			widget, &x, &y, &w, &h);
+		gdk_window_move_resize (button->event_window,
+					allocation->x,
+					allocation->y,
+					allocation->width,
+					allocation->height);
 
-		gdk_window_move_resize (button->event_window, x, y, w, h);
 	}
 }
 
@@ -731,11 +663,15 @@
 static gboolean
 button_widget_enter_notify (GtkWidget *widget, GdkEventCrossing *event)
 {
+    	gboolean in_button;
+
 	g_return_val_if_fail (BUTTON_IS_WIDGET (widget), FALSE);
 
+	in_button = GTK_BUTTON (widget)->in_button;
 	GTK_WIDGET_CLASS (parent_class)->enter_notify_event (widget, event);
-	if (GTK_BUTTON (widget)->in_button)
-		gtk_widget_queue_draw (widget);
+	if (in_button != GTK_BUTTON (widget)->in_button &&
+		panel_global_config_get_highlight_when_over ())
+	    		gtk_widget_queue_draw (widget);
 
 	return FALSE;
 }
@@ -818,7 +754,7 @@
 	gobject_class->set_property = button_widget_set_property;
 	  
 	widget_class->realize            = button_widget_realize;
-	widget_class->parent_set         = button_widget_parent_set;
+	widget_class->unrealize          = button_widget_unrealize;
 	widget_class->size_allocate      = button_widget_size_allocate;
 	widget_class->size_request       = button_widget_size_request;
 	widget_class->button_press_event = button_widget_button_press;
