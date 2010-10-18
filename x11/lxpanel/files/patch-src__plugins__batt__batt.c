--- src/plugins/batt/batt.c.orig	2010-02-08 07:37:52.000000000 +0100
+++ src/plugins/batt/batt.c	2010-10-16 19:33:35.871250014 +0200
@@ -30,7 +30,7 @@
  */
 
 /* FIXME:
- *  Here are somethings need to be improvec:
+ *  Here are somethings need to be improved:
  *  1. Replace pthread stuff with gthread counterparts for portability.
  *  3. Add an option to hide the plugin when AC power is used or there is no battery.
  *  4. Handle failure gracefully under systems other than Linux.
@@ -71,7 +71,7 @@
     GdkPixmap *pixmap;
     GtkWidget *drawingArea;
     int orientation;
-    unsigned int alarmTime,
+    unsigned int alarmPercentage,
         border,
         height,
         length,
@@ -120,21 +120,18 @@
     char tooltip[ 256 ];
     battery *b = lx_b->b;
     /* unit: mW */
-    int rate = lx_b->b->present_rate;
 
     if (! lx_b->pixmap )
         return;
 
     /* no battery is found */
-    if( b == NULL ) 
+    if( b == NULL || b->percentage < 0) 
     {
 	gtk_widget_set_tooltip_text( lx_b->drawingArea, _("No batteries found") );
+        gdk_draw_rectangle(lx_b->pixmap, lx_b->bg, TRUE, 0, 0, lx_b->width, lx_b->height);
 	return;
     }
     
-
-
-    
     gboolean isCharging;
     
     /* draw background */
@@ -145,8 +142,8 @@
     isCharging = battery_is_charging ( b );
     
     /* Consider running the alarm command */
-    if (! isCharging && rate && 
-	( ( battery_get_remaining( b ) / 60 ) < lx_b->alarmTime ) )
+    if (! isCharging && 
+	( ( b->percentage ) < lx_b->alarmPercentage ) )
     {
 	/* Shrug this should be done using glibs process functions */
 	/* Alarms should not run concurrently; determine whether an alarm is
@@ -176,7 +173,7 @@
 	    int left_seconds = b->seconds -= 3600 * hours;
 	    int minutes = left_seconds / 60;
 	    snprintf(tooltip, 256,
-		     _("Battery: %d%% charged, %d:%02d until full"),
+		     _("Battery: %d%% charged"),
 		     lx_b->b->percentage,
 		     hours,
 		     minutes );
@@ -187,10 +184,10 @@
 		int left_seconds = b->seconds -= 3600 * hours;
 		int minutes = left_seconds / 60;
                 snprintf(tooltip, 256,
-                        _("Battery: %d%% charged, %d:%02d left"),
+                        _("Battery: %d%% charged, %d:%02dh left"),
 			 lx_b->b->percentage,
-			 hours,
-			 minutes );
+			 lx_b->b->minutes / 60,
+			 lx_b->b->minutes % 60 );
             } else {
                 snprintf(tooltip, 256,
                         _("Battery: %d%% charged"),
@@ -374,7 +371,7 @@
             = lx_b->dischargingColor1 = lx_b->dischargingColor2 = NULL;
 
     /* Set default values for integers */
-    lx_b->alarmTime = 5;
+    lx_b->alarmPercentage = 10;
     lx_b->requestedBorder = 1;
 
     line s;
@@ -403,8 +400,8 @@
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
@@ -580,7 +577,7 @@
             _("Hide if there is no battery"), &b->hide_if_no_battery, CONF_TYPE_BOOL,
 #endif
             _("Alarm command"), &b->alarmCommand, CONF_TYPE_STR,
-            _("Alarm time (minutes left)"), &b->alarmTime, CONF_TYPE_INT,
+            _("Alarm percentage (Percentage left)"), &b->alarmPercentage, CONF_TYPE_INT,
             _("Background color"), &b->backgroundColor, CONF_TYPE_STR,
             _("Charging color 1"), &b->chargingColor1, CONF_TYPE_STR,
             _("Charging color 2"), &b->chargingColor2, CONF_TYPE_STR,
@@ -600,7 +597,7 @@
 
     lxpanel_put_bool(fp, "HideIfNoBattery",lx_b->hide_if_no_battery);
     lxpanel_put_str(fp, "AlarmCommand", lx_b->alarmCommand);
-    lxpanel_put_int(fp, "AlarmTime", lx_b->alarmTime);
+    lxpanel_put_int(fp, "AlarmPercentage", lx_b->alarmPercentage);
     lxpanel_put_str(fp, "BackgroundColor", lx_b->backgroundColor);
     lxpanel_put_int(fp, "BorderWidth", lx_b->requestedBorder);
     lxpanel_put_str(fp, "ChargingColor1", lx_b->chargingColor1);
