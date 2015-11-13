--- src/print_battery_info.c.orig	2014-01-05 03:34:07.000000000 -0800
+++ src/print_battery_info.c	2015-10-08 13:33:45.452887000 -0700
@@ -12,6 +12,7 @@
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
 #include <sys/types.h>
 #include <sys/sysctl.h>
+#include <dev/acpica/acpiio.h>
 #endif
 
 #if defined(__OpenBSD__)
@@ -215,7 +216,7 @@ void print_battery_info(yajl_gen json_ge
         state = sysctl_rslt;
         if (state == 0 && present_rate == 100)
                 status = CS_FULL;
-        else if (state == 0 && present_rate < 100)
+        else if ((state & ACPI_BATT_STAT_CHARGING) && present_rate < 100)
                 status = CS_CHARGING;
         else
                 status = CS_DISCHARGING;
@@ -227,7 +228,7 @@ void print_battery_info(yajl_gen json_ge
         (void)snprintf(percentagebuf, sizeof(percentagebuf), "%02d%%",
                        present_rate);
 
-        if (state == 1) {
+        if (state == ACPI_BATT_STAT_DISCHARG) {
                 int hours, minutes;
                 minutes = remaining;
                 hours = minutes / 60;
