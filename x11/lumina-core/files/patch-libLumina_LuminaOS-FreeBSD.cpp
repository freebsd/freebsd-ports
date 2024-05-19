--- libLumina/LuminaOS-FreeBSD.cpp.orig	2021-12-26 02:33:45 UTC
+++ libLumina/LuminaOS-FreeBSD.cpp
@@ -9,6 +9,8 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
+#include <sys/param.h>	// __FreeBSD_version
+#include <dev/acpica/acpiio.h>
 
 #include <QDebug>
 //can't read xbrightness settings - assume invalid until set
@@ -171,10 +173,29 @@ int LOS::audioVolume(){ //Returns: audio volume as a p
      audiovolume = out;
   }else{
     //probe the system for the current volume (other utils could be changing it)
+    // mixer interface changed in FreeBSD 14
+    // 13 and prior: mixer -S vol outputs
+    //	vol:50:50
+    // 14 and later, there is no -S flag, and vol is a fraction, not a %
+    // mixer -o vol outputs
+    //	vol.volume=0.75:0.75
+    //      vol.mute=0
+    // Might be better to use the mixer API instead
+#if __FreeBSD_version < 1400000
       QString info = LUtils::getCmdOutput("mixer -S vol").join(":").simplified(); //ignores any other lines
       if(!info.isEmpty()){
         int L = info.section(":",1,1).toInt();
         int R = info.section(":",2,2).toInt();
+#else
+      // Produce something like vol.volume=0.26:0.26=vol.mute=0=
+      // Multiple lines are joined, separated by '='
+      QString info = LUtils::getCmdOutput("mixer -o vol").join("=").simplified();
+      if(!info.isEmpty()){
+        int L = info.section(QRegularExpression("[=:]"),1,1).toDouble() * 100.0;
+        int R = info.section(QRegularExpression("[=:]"),2,2).toDouble() * 100.0;
+#endif
+
+
         if(L>R){ out = L; }
         else{ out = R; }
 	if(out != audiovolume){
@@ -195,10 +216,27 @@ void LOS::setAudioVolume(int percent){
   if(remoteSession){
     LUtils::runCmd(QString("pactl set-sink-volume @DEFAULT_SINK@ ")+QString::number(percent)+"%");
   }else{
-    QString info = LUtils::getCmdOutput("mixer -S vol").join(":").simplified(); //ignores any other lines
-    if(!info.isEmpty()){
-      int L = info.section(":",1,1).toInt();
-      int R = info.section(":",2,2).toInt();
+    // mixer interface changed in FreeBSD 14
+    // 13 and prior: mixer -S vol outputs
+    //	vol:50:50
+    // 14 and later, there is no -S flag, and vol is a fraction, not a %
+    // mixer -o vol outputs
+    //	vol.volume=0.75:0.75
+    //      vol.mute=0
+    // Might be better to use the mixer API instead
+#if __FreeBSD_version < 1400000
+      QString info = LUtils::getCmdOutput("mixer -S vol").join(":").simplified(); //ignores any other lines
+      if(!info.isEmpty()){
+        int L = info.section(":",1,1).toInt();
+        int R = info.section(":",2,2).toInt();
+#else
+      // Produce something like vol.volume=0.26:0.26=vol.mute=0=
+      // Multiple lines are joined, separated by '='
+      QString info = LUtils::getCmdOutput("mixer -o vol").join("=").simplified();
+      if(!info.isEmpty()){
+        int L = info.section(QRegularExpression("[=:]"),1,1).toDouble() * 100.0;
+        int R = info.section(QRegularExpression("[=:]"),2,2).toDouble() * 100.0;
+#endif
       int diff = L-R;
       if((percent == L) && (L==R)){ return; } //already set to that volume
       if(diff<0){ R=percent; L=percent+diff; } //R Greater
@@ -207,7 +245,11 @@ void LOS::setAudioVolume(int percent){
       if(L<0){L=0;}else if(L>100){L=100;}
       if(R<0){R=0;}else if(R>100){R=100;}
       //Run Command
+#if __FreeBSD_version < 1400000
       LUtils::runCmd("mixer vol "+QString::number(L)+":"+QString::number(R));
+#else
+      LUtils::runCmd("mixer vol="+QString::number(L/100.0)+":"+QString::number(R/100.0));
+#endif
     }
   }
   audiovolume = percent; //save for checking later
@@ -220,15 +262,36 @@ void LOS::changeAudioVolume(int percentdiff){
   if(remoteSession){
     LUtils::runCmd(QString("pactl set-sink-volume @DEFAULT_SINK@ ")+((percentdiff>0)?"+" : "") + QString::number(percentdiff)+"%");
   }else{
-    QString info = LUtils::getCmdOutput("mixer -S vol").join(":").simplified(); //ignores any other lines
-    if(!info.isEmpty()){
-      int L = info.section(":",1,1).toInt() + percentdiff;
-      int R = info.section(":",2,2).toInt() + percentdiff;
+    // mixer interface changed in FreeBSD 14
+    // 13 and prior: mixer -S vol outputs
+    //	vol:50:50
+    // 14 and later, there is no -S flag, and vol is a fraction, not a %
+    // mixer -o vol outputs
+    //	vol.volume=0.75:0.75
+    //      vol.mute=0
+    // Might be better to use the mixer API instead
+#if __FreeBSD_version < 1400000
+      QString info = LUtils::getCmdOutput("mixer -S vol").join(":").simplified(); //ignores any other lines
+      if(!info.isEmpty()){
+        int L = info.section(":",1,1).toInt();
+        int R = info.section(":",2,2).toInt();
+#else
+      // Produce something like vol.volume=0.26:0.26=vol.mute=0=
+      // Multiple lines are joined, separated by '='
+      QString info = LUtils::getCmdOutput("mixer -o vol").join("=").simplified();
+      if(!info.isEmpty()){
+        int L = info.section(QRegularExpression("[=:]"),1,1).toDouble() * 100.0;
+        int R = info.section(QRegularExpression("[=:]"),2,2).toDouble() * 100.0;
+#endif
       //Check bounds
       if(L<0){L=0;}else if(L>100){L=100;}
       if(R<0){R=0;}else if(R>100){R=100;}
       //Run Command
+#if __FreeBSD_version < 1400000
       LUtils::runCmd("mixer vol "+QString::number(L)+":"+QString::number(R));
+#else
+      LUtils::runCmd("mixer vol="+QString::number(L/100.0)+":"+QString::number(R/100.0));
+#endif
     }
   }
 }
@@ -289,31 +352,53 @@ void LOS::systemSuspend(){
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
