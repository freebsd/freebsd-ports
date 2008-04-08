--- applets/clock/clock-location.c.orig	2008-04-07 17:17:51.000000000 -0400
+++ applets/clock/clock-location.c	2008-04-07 22:54:31.000000000 -0400
@@ -27,6 +27,8 @@
 #include "clock-marshallers.h"
 #include "set-timezone.h"
 
+#define daylight 1
+
 G_DEFINE_TYPE (ClockLocation, clock_location, G_TYPE_OBJECT)
 
 typedef struct {
@@ -62,6 +64,7 @@ static void clock_location_unset_tz (Clo
 static void setup_weather_updates (ClockLocation *loc);
 static void add_to_network_monitor (ClockLocation *loc);
 static void remove_from_network_monitor (ClockLocation *loc);
+static gchar *clock_location_guess_zone (ClockZoneTable *zones);
 
 #define PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), CLOCK_LOCATION_TYPE, ClockLocationPrivate))
 
@@ -299,7 +302,11 @@ zone_from_etc_sysconfig_clock (void)
 
 		parse_etc_sysconfig_clock ();
 		
+#ifndef __FreeBSD__
 		file = g_file_new_for_path ("/etc/sysconfig/clock");
+#else
+		file = g_file_new_for_path ("/etc/localtime");
+#endif
 
 		monitor = g_file_monitor_file (file, G_FILE_MONITOR_NONE,
 					       NULL, NULL);
@@ -642,12 +649,18 @@ gboolean
 clock_location_is_current_timezone (ClockLocation *loc)
 {
         ClockLocationPrivate *priv = PRIVATE (loc);
-	const char *zone;
+	ClockZoneTable *zones;
+	char *zone;
 
-	if ((zone = zone_from_etc_sysconfig_clock ()))
+	zones = clock_zonetable_new (SYSTEM_ZONEINFODIR);
+	if ((zone = clock_location_guess_zone (zones))) {
+		g_object_unref (zones);
 		return strcmp (zone, priv->timezone) == 0;
-	else
-		return clock_location_get_offset (loc) == 0;
+	}
+
+	g_object_unref (zones);
+
+	return clock_location_get_offset (loc) == 0;
 }
 
 gboolean
