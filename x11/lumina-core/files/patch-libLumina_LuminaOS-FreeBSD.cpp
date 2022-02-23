--- libLumina/LuminaOS-FreeBSD.cpp.orig	2021-12-26 02:33:45 UTC
+++ libLumina/LuminaOS-FreeBSD.cpp
@@ -9,6 +9,7 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
+#include <dev/acpica/acpiio.h>
 
 #include <QDebug>
 //can't read xbrightness settings - assume invalid until set
@@ -289,31 +290,53 @@ void LOS::systemSuspend(){
 }
 
 //Battery Availability
+// apm command is not available on powerpc or arm
 bool LOS::hasBattery(){
   static int hasbat = -1;
+  int        life;
+  size_t     len = sizeof(life);
   if(hasbat < 0 ){
-    int val = batteryCharge();
-    if(val >= 0 && val <= 100){ hasbat = 1; }
-    else{ hasbat = 0; }
+    if ( sysctlbyname("hw.acpi.battery.life", &life, &len, NULL, 0) == 0 )
+      hasbat = 1;
+    else
+      hasbat = 0;
   }
   return (hasbat==1);
 }
 
 //Battery Charge Level
+// apm command is not available on powerpc or arm
 int LOS::batteryCharge(){ //Returns: percent charge (0-100), anything outside that range is counted as an error
-  int charge = LUtils::getCmdOutput("apm -l").join("").toInt();
-  if(charge > 100){ charge = -1; } //invalid charge
-  return charge;
+  int    life;	// sysctl name
+  size_t len = sizeof(life);
+  if ( (sysctlbyname("hw.acpi.battery.life", &life, &len, NULL, 0) != 0) ||
+       (life > 100) )
+     life = -1; //invalid charge
+  return life;
 }
 
 //Battery Charging State
+// apm command is not available on powerpc or arm
 bool LOS::batteryIsCharging(){
-  return (LUtils::getCmdOutput("apm -a").join("").simplified() == "1");
+  int	 state;
+  size_t len = sizeof(state);
+  if ( (sysctlbyname("hw.acpi.battery.state", &state, &len, NULL, 0) == 0) &&
+       (state == ACPI_BATT_STAT_CHARGING) )
+    return true;
+  else
+    return false;
 }
 
 //Battery Time Remaining
+// apm command is not available on powerpc or arm
 int LOS::batterySecondsLeft(){ //Returns: estimated number of seconds remaining
-  return LUtils::getCmdOutput("apm -t").join("").toInt();
+  int	 min;
+  size_t len = sizeof(min);
+  if ( LOS::batteryIsCharging() ||
+       (sysctlbyname("hw.acpi.battery.time", &min, &len, NULL, 0) != 0) )
+    return -1;
+  else
+    return min * 60;
 }
 
 //File Checksums
