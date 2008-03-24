--- applets/clock/clock-location.c.orig	2008-03-22 21:14:45.000000000 -0400
+++ applets/clock/clock-location.c	2008-03-23 02:11:34.000000000 -0400
@@ -28,6 +28,8 @@
 #include "set-timezone.h"
 #include "gweather-xml.h"
 
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
 
@@ -271,7 +274,6 @@ parse_etc_sysconfig_clock (void)
 			}
 		}
 	}
-
 out:
 	if (lines)
 		g_strfreev (lines);
@@ -298,7 +300,11 @@ zone_from_etc_sysconfig_clock (void)
 
 		parse_etc_sysconfig_clock ();
 		
+#ifndef __FreeBSD__
 		file = g_file_new_for_path ("/etc/sysconfig/clock");
+#else
+		file = g_file_new_for_path ("/etc/localtime");
+#endif
 
 		monitor = g_file_monitor_file (file, G_FILE_MONITOR_NONE,
 					       NULL, NULL);
@@ -632,10 +638,17 @@ gboolean
 clock_location_is_current (ClockLocation *loc)
 {
         ClockLocationPrivate *priv = PRIVATE (loc);
-	const char *zone;
+	ClockZoneTable *zones;
+	char *zone;
 
-	if ((zone = zone_from_etc_sysconfig_clock ()))
+	zones = clock_zonetable_new (SYSTEM_ZONEINFODIR);
+
+	if ((zone = clock_location_guess_zone (zones))) {
+		g_object_unref (zones);
 		return strcmp (zone, priv->timezone) == 0;
+	}
+
+	g_object_unref (zones);
 
 	return clock_location_get_offset (loc) == 0;
 }
