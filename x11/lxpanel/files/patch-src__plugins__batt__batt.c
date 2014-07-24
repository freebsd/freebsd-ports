--- ./src/plugins/batt/batt.c.orig	2014-05-09 09:15:04.000000000 -0400
+++ ./src/plugins/batt/batt.c	2014-05-27 18:13:59.000000000 -0400
@@ -68,7 +68,7 @@
     cairo_surface_t *pixmap;
     GtkWidget *drawingArea;
     int orientation;
-    unsigned int alarmTime,
+    unsigned int alarmPercentage,
         border,
         height,
         length,
@@ -118,7 +118,6 @@
     char tooltip[ 256 ];
     battery *b = lx_b->b;
     /* unit: mW */
-    int rate;
     gboolean isCharging;
 
     if (! lx_b->pixmap )
@@ -127,26 +126,28 @@
     cr = cairo_create(lx_b->pixmap);
     cairo_set_line_width (cr, 1.0);
 
-    /* draw background */
-    gdk_cairo_set_source_color(cr, &lx_b->background);
-    cairo_rectangle(cr, 0, 0, lx_b->width, lx_b->height);
-    cairo_fill(cr);
-
     /* no battery is found */
-    if( b == NULL ) 
+    if( b == NULL || b->percentage < 0 )
     {
 	gtk_widget_set_tooltip_text( lx_b->drawingArea, _("No batteries found") );
-	goto update_done;
+	gdk_cairo_set_source_color(cr, &lx_b->background);
+	cairo_rectangle(cr, 0, 0, lx_b->width, lx_b->height);
+	cairo_fill(cr);
+	return;
     }
     
+    /* draw background */
+    gdk_cairo_set_source_color(cr, &lx_b->background);
+    cairo_rectangle(cr, 0, 0, lx_b->width, lx_b->height);
+    cairo_fill(cr);
+
     /* fixme: only one battery supported */
 
-    rate = lx_b->b->current_now;
     isCharging = battery_is_charging ( b );
     
     /* Consider running the alarm command */
-    if ( !isCharging && rate > 0 &&
-	( ( battery_get_remaining( b ) / 60 ) < lx_b->alarmTime ) )
+    if ( !isCharging &&
+	( ( b->percentage ) < lx_b->alarmPercentage ) )
     {
 	/* Shrug this should be done using glibs process functions */
 	/* Alarms should not run concurrently; determine whether an alarm is
@@ -176,7 +177,7 @@
 	int left_seconds = b->seconds - 3600 * hours;
 	int minutes = left_seconds / 60;
 	snprintf(tooltip, 256,
-		_("Battery: %d%% charged, %d:%02d until full"),
+		_("Battery: %d%% charged"),
 		lx_b->b->percentage,
 		hours,
 		minutes );
@@ -187,10 +188,10 @@
 	    int left_seconds = b->seconds - 3600 * hours;
 	    int minutes = left_seconds / 60;
 	    snprintf(tooltip, 256,
-		    _("Battery: %d%% charged, %d:%02d left"),
+		    _("Battery: %d%% charged, %d:%02dh left"),
 		    lx_b->b->percentage,
-		    hours,
-		    minutes );
+                    hours,
+                    minutes);
 	} else {
 	    snprintf(tooltip, 256,
 		    _("Battery: %d%% charged"),
@@ -236,8 +237,6 @@
         cairo_fill(cr);
 
     }
-
-update_done:
     if( repaint )
 	gtk_widget_queue_draw( lx_b->drawingArea );
 
@@ -247,19 +246,12 @@
 
 /* This callback is called every 3 seconds */
 static int update_timout(lx_battery *lx_b) {
-    battery *bat;
     GDK_THREADS_ENTER();
     lx_b->state_elapsed_time++;
     lx_b->info_elapsed_time++;
 
-    bat = battery_update( lx_b->b );
-    if (bat == NULL)
-    {
-	battery_free(lx_b->b);
-
-	/* maybe in the mean time a battery has been inserted. */
-	lx_b->b = battery_get();
-    }
+    /* check the  batteries every 3 seconds */
+    battery_update( lx_b->b );
 
     update_display( lx_b, TRUE );
 
@@ -346,6 +338,10 @@
     /* get available battery */
     lx_b->b = battery_get ();
     
+    /* no battery available */
+    if ( lx_b->b == NULL )
+	goto error;
+    
     p->pwid = gtk_event_box_new();
     GTK_WIDGET_SET_FLAGS( p->pwid, GTK_NO_WINDOW );
     gtk_container_set_border_width( GTK_CONTAINER(p->pwid), 1 );
@@ -380,7 +376,7 @@
             = lx_b->dischargingColor1 = lx_b->dischargingColor2 = NULL;
 
     /* Set default values for integers */
-    lx_b->alarmTime = 5;
+    lx_b->alarmPercentage = 10;
     lx_b->requestedBorder = 1;
 
     line s;
@@ -409,8 +405,8 @@
                     lx_b->dischargingColor1 = g_strdup(s.t[1]);
                 else if (!g_ascii_strcasecmp(s.t[0], "DischargingColor2"))
                     lx_b->dischargingColor2 = g_strdup(s.t[1]);
-                else if (!g_ascii_strcasecmp(s.t[0], "AlarmTime"))
-                    lx_b->alarmTime = atoi(s.t[1]);
+                else if (!g_ascii_strcasecmp(s.t[0], "AlarmPercentage"))
+                    lx_b->alarmPercentage = atoi(s.t[1]);
                 else if (!g_ascii_strcasecmp(s.t[0], "BorderWidth"))
                     lx_b->requestedBorder = atoi(s.t[1]);
                 else if (!g_ascii_strcasecmp(s.t[0], "Size")) {
@@ -477,9 +473,6 @@
 
     lx_battery *b = (lx_battery *) p->priv;
 
-    if (b->b != NULL)
-	battery_free(b->b);
-
     if (b->pixmap)
         cairo_surface_destroy(b->pixmap);
 
@@ -562,7 +555,7 @@
             _("Hide if there is no battery"), &b->hide_if_no_battery, CONF_TYPE_BOOL,
 #endif
             _("Alarm command"), &b->alarmCommand, CONF_TYPE_STR,
-            _("Alarm time (minutes left)"), &b->alarmTime, CONF_TYPE_INT,
+            _("Alarm percentage (percentage left)"), &b->alarmPercentage, CONF_TYPE_INT,
             _("Background color"), &b->backgroundColor, CONF_TYPE_STR,
             _("Charging color 1"), &b->chargingColor1, CONF_TYPE_STR,
             _("Charging color 2"), &b->chargingColor2, CONF_TYPE_STR,
@@ -582,7 +575,7 @@
 
     lxpanel_put_bool(fp, "HideIfNoBattery",lx_b->hide_if_no_battery);
     lxpanel_put_str(fp, "AlarmCommand", lx_b->alarmCommand);
-    lxpanel_put_int(fp, "AlarmTime", lx_b->alarmTime);
+    lxpanel_put_int(fp, "AlarmPercentage", lx_b->alarmPercentage);
     lxpanel_put_str(fp, "BackgroundColor", lx_b->backgroundColor);
     lxpanel_put_int(fp, "BorderWidth", lx_b->requestedBorder);
     lxpanel_put_str(fp, "ChargingColor1", lx_b->chargingColor1);
