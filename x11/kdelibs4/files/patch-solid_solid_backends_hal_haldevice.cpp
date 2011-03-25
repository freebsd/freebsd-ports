--- ./solid/solid/backends/hal/haldevice.cpp.orig	2011-02-25 22:53:32.000000000 +0100
+++ ./solid/solid/backends/hal/haldevice.cpp	2011-03-14 11:44:20.293518650 +0100
@@ -199,7 +199,7 @@
             return "computer";
         }
 
-    } else if (category=="storage") {
+    } else if (category=="storage" || category=="storage.cdrom") {
 
         if (prop("storage.drive_type").toString()=="floppy") {
             return "media-floppy";
@@ -222,7 +222,7 @@
 
         return "drive-harddisk";
 
-    } else if (category=="volume") {
+    } else if (category=="volume" || category=="volume.disc") {
 
         QStringList capabilities = prop("info.capabilities").toStringList();
 
@@ -350,9 +350,9 @@
 {
     QString category = prop("info.category").toString();
 
-    if (category=="storage") {
+    if (category=="storage" || category=="storage.cdrom") {
         return storageDescription();
-    } else if (category=="volume") {
+    } else if (category=="volume" || category=="volume.disc") {
         return volumeDescription();
     } else if (category=="net.80211") {
         return QObject::tr("WLAN Interface");
