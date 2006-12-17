--- eworkpanel/batterymonitor.cpp.orig	Sun Dec 17 12:05:20 2006
+++ eworkpanel/batterymonitor.cpp	Sun Dec 17 12:04:43 2006
@@ -10,6 +10,9 @@
 // GNU General Public Licence version 2 or newer.
 // See COPYING for details.
 
+#include <unistd.h>
+#include <fcntl.h>
+
 #include "batterymonitor.h"
 
 #include "icons/poweron.xpm"
@@ -151,7 +154,7 @@
 #include <machine/apmioctl.h>
 
 int first = 1;
-void battery_check(void)
+void BatteryMonitor::battery_check(void)
 {
   int fd;
   struct apmreq ar ;
@@ -213,7 +216,7 @@
 #define        APM_STAT_BATT_CHARGING  3
 
 int first = 1;
-void battery_check(void)
+void BatteryMonitor::battery_check(void)
 {
   int fd, r;
   bool p;
