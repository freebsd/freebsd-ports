--- ./plasma/generic/applets/batterymonitor/contents/ui/batterymonitor.qml.orig	2013-05-03 06:36:45.739116000 +0200
+++ ./plasma/generic/applets/batterymonitor/contents/ui/batterymonitor.qml	2013-06-11 00:33:16.141003089 +0200
@@ -186,7 +186,7 @@
         }
 
         property int cumulativePercent
-        property bool cumulativePluggedin: count > 0
+        property bool cumulativePluggedin
         // true  --> all batteries charged
         // false --> one of the batteries charging/discharging
         property bool allCharged
