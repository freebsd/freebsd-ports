--- src/plugins/batt/batt.c.orig	2012-05-20 09:57:39.000000000 -0400
+++ src/plugins/batt/batt.c	2012-09-05 13:18:22.428078608 -0400
@@ -71,7 +71,7 @@
     GdkPixmap *pixmap;
     GtkWidget *drawingArea;
     int orientation;
-    unsigned int alarmTime,
+    unsigned int alarmPercentage,
         border,
         height,
         length,
@@ -120,16 +120,16 @@
     char tooltip[ 256 ];
     battery *b = lx_b->b;
     /* unit: mW */
-    int rate;
     gboolean isCharging;
 
     if (! lx_b->pixmap )
         return;
 
     /* no battery is found */
-    if( b == NULL ) 
+    if( b == NULL || b->percentage < 0 )
     {
 	gtk_widget_set_tooltip_text( lx_b->drawingArea, _("No batteries found") );
+        gdk_draw_rectangle(lx_b->pixmap, lx_b->bg, TRUE, 0, 0, lx_b->width, lx_b->height);
 	return;
     }
     
@@ -138,12 +138,11 @@
 
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
@@ -173,7 +172,7 @@
 	int left_seconds = b->seconds - 3600 * hours;
 	int minutes = left_seconds / 60;
 	snprintf(tooltip, 256,
-		_("Battery: %d%% charged, %d:%02d until full"),
+		_("Battery: %d%% charged"),
 		lx_b->b->percentage,
 		hours,
 		minutes );
@@ -184,10 +183,10 @@
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
@@ -367,7 +366,7 @@
             = lx_b->dischargingColor1 = lx_b->dischargingColor2 = NULL;
 
     /* Set default values for integers */
-    lx_b->alarmTime = 5;
+    lx_b->alarmPercentage = 10;
     lx_b->requestedBorder = 1;
 
     line s;
@@ -396,8 +395,8 @@
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
@@ -573,7 +572,7 @@
             _("Hide if there is no battery"), &b->hide_if_no_battery, CONF_TYPE_BOOL,
 #endif
             _("Alarm command"), &b->alarmCommand, CONF_TYPE_STR,
-            _("Alarm time (minutes left)"), &b->alarmTime, CONF_TYPE_INT,
+            _("Alarm percentage (percentage left)"), &b->alarmPercentage, CONF_TYPE_INT,
             _("Background color"), &b->backgroundColor, CONF_TYPE_STR,
             _("Charging color 1"), &b->chargingColor1, CONF_TYPE_STR,
             _("Charging color 2"), &b->chargingColor2, CONF_TYPE_STR,
@@ -593,7 +592,7 @@
 
     lxpanel_put_bool(fp, "HideIfNoBattery",lx_b->hide_if_no_battery);
     lxpanel_put_str(fp, "AlarmCommand", lx_b->alarmCommand);
-    lxpanel_put_int(fp, "AlarmTime", lx_b->alarmTime);
+    lxpanel_put_int(fp, "AlarmPercentage", lx_b->alarmPercentage);
     lxpanel_put_str(fp, "BackgroundColor", lx_b->backgroundColor);
     lxpanel_put_int(fp, "BorderWidth", lx_b->requestedBorder);
     lxpanel_put_str(fp, "ChargingColor1", lx_b->chargingColor1);
