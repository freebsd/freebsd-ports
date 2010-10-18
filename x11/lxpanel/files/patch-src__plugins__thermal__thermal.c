--- ./src/plugins/thermal/thermal.c.orig	2010-10-09 15:45:51.496346000 +0200
+++ ./src/plugins/thermal/thermal.c	2010-10-09 16:51:40.227196000 +0200
@@ -32,10 +32,7 @@
 
 #include "dbg.h"
 
-#define THERMAL_DIRECTORY "/proc/acpi/thermal_zone/" /* must be slash-terminated */
-#define THERMAL_TEMPF  "temperature"
-#define THERMAL_TRIP  "trip_points"
-#define TRIP_CRITICAL "critical (S5):"
+#include <sys/sysctl.h>
 
 typedef struct {
     Plugin * plugin;
@@ -57,68 +54,33 @@
 } thermal;
 
 static gint
-get_critical(thermal *th){
-    FILE *state;
-    char buf[ 256 ], sstmp [ 100 ];
-    char* pstr;
-
-    if(th->sensor == NULL) return -1;
-
-    sprintf(sstmp,"%s%s",th->sensor,THERMAL_TRIP);
-
-    if (!(state = fopen( sstmp, "r"))) {
-        //printf("cannot open %s\n",sstmp);
-        return -1;
-    }
+get_temperature_value(thermal *th, const char *which)
+{
+	char sstmp[ 100 ];
+	int t;
+	size_t tlen = sizeof t;
 
-    while( fgets(buf, 256, state) &&
-            ! ( pstr = strstr(buf, TRIP_CRITICAL) ) );
-    if( pstr )
-    {
-        pstr += strlen(TRIP_CRITICAL);
-        while( *pstr && *pstr == ' ' )
-            ++pstr;
+	if(th->sensor == NULL) return -1;
 
-        pstr[strlen(pstr)-3] = '\0';
-        printf("Critical: [%s]\n",pstr);
-        fclose(state);
-        return atoi(pstr);
-    }
+	snprintf(sstmp, sizeof(sstmp), "hw.acpi.thermal.%s.%s", th->sensor, which);
+	if (sysctlbyname(sstmp, &t, &tlen, NULL, 0) != 0 || tlen != sizeof t)
+		return -1;
 
-    fclose(state);
-    return -1;
+	return (t - 2732) / 10;
 }
 
 static gint
-get_temperature(thermal *th){
-    FILE *state;
-    char buf[ 256 ], sstmp [ 100 ];
-    char* pstr;
-
-    if(th->sensor == NULL) return -1;
-
-    sprintf(sstmp,"%s%s",th->sensor,THERMAL_TEMPF);
-
-    if (!(state = fopen( sstmp, "r"))) {
-        //printf("cannot open %s\n",sstmp);
-        return -1;
-    }
+get_critical(thermal *th)
+{
 
-    while( fgets(buf, 256, state) &&
-            ! ( pstr = strstr(buf, "temperature:") ) );
-    if( pstr )
-    {
-        pstr += 12;
-        while( *pstr && *pstr == ' ' )
-            ++pstr;
+	return (get_temperature_value(th, "_CRT"));
+}
 
-        pstr[strlen(pstr)-3] = '\0';
-        fclose(state);
-        return atoi(pstr);
-    }
+static gint
+get_temperature(thermal *th)
+{
 
-    fclose(state);
-    return -1;
+	return (get_temperature_value(th, "temperature"));
 }
 
 static gint
@@ -141,7 +103,7 @@
         panel_draw_label_text(th->plugin->panel, th->namew, "NA", TRUE, TRUE);
     else
     {
-        n = sprintf(buffer, "<span color=\"#%06x\"><b>%02d</b></span>", gcolor2rgb24(&color), temp);
+        n = sprintf(buffer, "<span color=\"#%06x\"><b>%02d C</b></span>", gcolor2rgb24(&color), temp);
         gtk_label_set_markup (GTK_LABEL(th->namew), buffer) ;
     }
 
@@ -151,30 +113,8 @@
 static void
 check_sensors( thermal* th )
 {
-    GDir *sensorsDirectory;
-    const char *sensor_name;
-    char sensor_path[100];
 
-    if (! (sensorsDirectory = g_dir_open(THERMAL_DIRECTORY, 0, NULL)))
-    {
-        th->sensor = NULL;
-        return;
-    }
-
-    /* Scan the thermal_zone directory for available sensors */
-    while ((sensor_name = g_dir_read_name(sensorsDirectory))) {
-        if (sensor_name[0] != '.') {
-            sprintf(sensor_path,"%s%s/",THERMAL_DIRECTORY, sensor_name);
-            if(th->sensor) { 
-                g_free(th->sensor);
-                th->sensor = NULL; 
-            }
-            th->sensor = strdup(sensor_path);
-            //printf("sensor: %s\n", b->sensor);
-            break;
-        }
-    }
-    g_dir_close(sensorsDirectory);
+	th->sensor = strdup("tz0");
 }
 
 static int
