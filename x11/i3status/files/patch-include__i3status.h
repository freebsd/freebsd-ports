--- ./include/i3status.h.orig	2011-07-21 23:11:48.000000000 +0200
+++ ./include/i3status.h	2011-12-08 14:48:47.000000000 +0100
@@ -16,7 +16,8 @@
 
 #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 
-#define THERMAL_ZONE "hw.acpi.thermal.tz%d.temperature"
+/* this needs the coretemp module to be loaded */
+#define THERMAL_ZONE "dev.cpu.%d.temperature"
 #define BATT_LIFE "hw.acpi.battery.life"
 #define BATT_TIME "hw.acpi.battery.time"
 #define BATT_STATE "hw.acpi.battery.state"
