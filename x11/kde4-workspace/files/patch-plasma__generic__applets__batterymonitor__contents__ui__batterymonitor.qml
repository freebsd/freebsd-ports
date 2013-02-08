--- ./plasma/generic/applets/batterymonitor/contents/ui/batterymonitor.qml.orig	2012-08-13 10:54:40.000000000 +0200
+++ ./plasma/generic/applets/batterymonitor/contents/ui/batterymonitor.qml	2012-09-27 16:19:28.837589000 +0200
@@ -48,7 +48,7 @@
             onClicked: plasmoid.togglePopup()
 
             property QtObject pmSource: plasmoid.rootItem.pmSource
-            property bool hasBattery: pmSource.data["Battery"]["Has Battery"]
+            property bool hasBattery: pmSource.data["Battery"]["Has Battery"] && pmSource.data["Battery0"]["Plugged in"]
             property int percent: pmSource.data["Battery0"]["Percent"]
             property string batteryState: pmSource.data["Battery0"]["State"]
             property bool pluggedIn: pmSource.data["AC Adapter"]["Plugged in"]
@@ -135,10 +135,10 @@
     property QtObject pmSource: PlasmaCore.DataSource {
         id: pmSource
         engine: "powermanagement"
-        connectedSources: ["AC Adapter", "Battery", "Battery0", "PowerDevil", "Sleep States"]
+        connectedSources: sources
         onDataChanged: {
             var status = "PassiveStatus";
-            if (data["Battery"]["Has Battery"]) {
+            if (data["Battery"]["Has Battery"] && data["Battery0"]["Plugged in"]) {
                 if (data["Battery0"]["Percent"] <= 10) {
                     status = "NeedsAttentionStatus";
                 } else if (data["Battery0"]["State"] != "NoCharge") {
@@ -147,16 +147,6 @@
             }
             plasmoid.status = status;
         }
-        onSourceAdded: {
-            if (source == "Battery0") {
-                connectSource(source)
-            }
-        }
-        onSourceRemoved: {
-            if (source == "Battery0") {
-                disconnectSource(source)
-            }
-        }
     }
 
     function stringForState(state, percent) {
@@ -173,7 +163,7 @@
         id: dialogItem
         percent: pmSource.data["Battery0"]["Percent"]
         batteryState: pmSource.data["Battery0"]["State"]
-        hasBattery: pmSource.data["Battery"]["Has Battery"]
+        hasBattery: pmSource.data["Battery"]["Has Battery"] && pmSource.data["Battery0"]["Plugged in"]
         pluggedIn: pmSource.data["AC Adapter"]["Plugged in"]
         screenBrightness: pmSource.data["PowerDevil"]["Screen Brightness"]
         remainingMsec: parent.show_remaining_time ? Number(pmSource.data["Battery"]["Remaining msec"]) : 0
