--- ./plasma/generic/applets/batterymonitor/contents/code/logic.js.orig	2013-05-03 06:36:45.739116000 +0200
+++ ./plasma/generic/applets/batterymonitor/contents/code/logic.js	2013-06-11 00:33:16.130983470 +0200
@@ -24,10 +24,12 @@
 function updateCumulative() {
     var sum = 0;
     var charged = true;
+    batteries.cumulativePluggedin = false;
     for (var i=0; i<batteries.count; i++) {
         var b = batteries.get(i);
         if (b["Plugged in"]) {
             sum += b["Percent"];
+            batteries.cumulativePluggedin = true;
         }
         if (b["State"] != "NoCharge") {
             charged = false;
