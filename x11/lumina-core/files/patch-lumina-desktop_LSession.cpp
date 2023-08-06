--- lumina-desktop/LSession.cpp.orig	2021-12-26 02:33:45 UTC
+++ lumina-desktop/LSession.cpp
@@ -97,46 +97,96 @@ LSession::~LSession(){
 //Static function so everything can get the same icon name
 QString LSession::batteryIconName(int charge, bool charging){
   int icon = -1;
-  if (charge > 90) { icon = 4; }
-  else if (charge > 70) { icon = 3; }
-  else if (charge > 20) { icon = 2; }
-  else if (charge > 5) { icon = 1; }
-  else if (charge > 0 ) { icon = 0; }
-  if(charging){ icon = icon+10; }
+
+  // Add 5% in order to round to nearest 10%
+  // E.g. 85% to 94% will show 90% icon
+  icon = (charge + 5) / 10;
+
+  //if (charge > 90) { icon = 4; }
+  //else if (charge > 70) { icon = 3; }
+  //else if (charge > 20) { icon = 2; }
+  //else if (charge > 5) { icon = 1; }
+  //else if (charge > 0 ) { icon = 0; }
+
+  if(charging){ icon += 11; }
+
+  // Some icons may not be available for some themes, so build a list
+  // of alternatives
   QStringList iconList;
     switch (icon) {
+
+      // Draining
       case 0:
-        iconList << "battery-20" << "battery-020" << "battery-empty" << "battery-caution";
+        iconList << "battery-00" << "battery-000" << "battery-empty" << "battery-caution";
         break;
       case 1:
-        iconList << "battery-40" << "battery-040" << "battery-low" << "battery-caution";
+        iconList << "battery-10" << "battery-010" << "battery-low" << "battery-caution";
         break;
       case 2:
-        iconList << "battery-60" << "battery-060" << "battery-good";
+        iconList << "battery-20" << "battery-020" << "battery-low" << "battery-caution";
         break;
       case 3:
-        iconList << "battery-80" << "battery-080" << "battery-good";
+        iconList << "battery-30" << "battery-030" << "battery-low" << "battery-caution";
         break;
       case 4:
-        iconList << "battery-100" << "battery-full";
+        iconList << "battery-40" << "battery-040" << "battery-good";
         break;
+      case 5:
+        iconList << "battery-50" << "battery-050" << "battery-good";
+        break;
+      case 6:
+        iconList << "battery-60" << "battery-060" << "battery-good";
+        break;
+      case 7:
+        iconList << "battery-70" << "battery-070" << "battery-good";
+        break;
+      case 8:
+        iconList << "battery-80" << "battery-080" << "battery-good";
+        break;
+      case 9:
       case 10:
+        iconList << "battery-100" << "battery-full";
+        break;
+
+      // Charging
+      case 11:
+        iconList << "battery-00-charging" << "battery-000-charging" << "battery-empty-charging" << "battery-caution-charging"
+		<< "battery-charging-00" << "battery-charging-000" << "battery-charging-empty" << "battery-charging-caution";
+        break;
+      case 12:
+        iconList << "battery-01-charging" << "battery-010-charging" << "battery-empty-charging" << "battery-caution-charging"
+		<< "battery-charging-01" << "battery-charging-010" << "battery-charging-empty" << "battery-charging-caution";
+        break;
+      case 13:
         iconList << "battery-20-charging" << "battery-020-charging" << "battery-empty-charging" << "battery-caution-charging"
 		<< "battery-charging-20" << "battery-charging-020" << "battery-charging-empty" << "battery-charging-caution";
         break;
-      case 11:
+      case 14:
+        iconList << "battery-30-charging" << "battery-030-charging" << "battery-low-charging" << "battery-caution-charging"
+		<< "battery-charging-30" << "battery-charging-030" << "battery-charging-low" << "battery-charging-caution";
+        break;
+      case 15:
         iconList << "battery-40-charging" << "battery-040-charging" << "battery-low-charging" << "battery-caution-charging"
 		<< "battery-charging-40" << "battery-charging-040" << "battery-charging-low" << "battery-charging-caution";
         break;
-      case 12:
+      case 16:
+        iconList << "battery-50-charging" << "battery-050-charging" << "battery-low-charging" << "battery-caution-charging"
+		<< "battery-charging-50" << "battery-charging-050" << "battery-charging-low" << "battery-charging-caution";
+        break;
+      case 17:
         iconList << "battery-60-charging" << "battery-060-charging" << "battery-good-charging"
 		<< "battery-charging-60" << "battery-charging-060" << "battery-charging-good";
         break;
-      case 13:
+      case 18:
+        iconList << "battery-70-charging" << "battery-070-charging" << "battery-good-charging"
+		<< "battery-charging-70" << "battery-charging-070" << "battery-charging-good";
+        break;
+      case 19:
         iconList << "battery-80-charging" << "battery-080-charging" << "battery-good-charging"
 		<< "battery-charging-80" << "battery-charging-080" << "battery-charging-good";
         break;
-      case 14:
+      case 20:
+      case 21:
         if(charge==100){ iconList << "battery-full-charged"; }
         iconList << "battery-100-charging" << "battery-full-charging"
 		<< "battery-charging-100" << "battery-charging-full";
