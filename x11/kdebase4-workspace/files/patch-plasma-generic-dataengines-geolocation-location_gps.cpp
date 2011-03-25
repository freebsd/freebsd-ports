--- plasma/generic/dataengines/geolocation/location_gps.cpp.orig	2011-03-23 00:33:55.000000000 +0300
+++ plasma/generic/dataengines/geolocation/location_gps.cpp	2011-03-23 00:48:57.000000000 +0300
@@ -17,7 +17,7 @@
 
 #include "location_gps.h"
 
-Gpsd::Gpsd(gps_data_t* gpsdata)
+Gpsd::Gpsd(gps_data_t gpsdata)
     : m_gpsdata(gpsdata)
     , m_abort(false)
 {
@@ -41,24 +41,20 @@
 
 void Gpsd::run()
 {
-#if defined( GPSD_API_MAJOR_VERSION ) && ( GPSD_API_MAJOR_VERSION >= 3 ) && defined( WATCH_ENABLE )
-    gps_stream(m_gpsdata, WATCH_ENABLE, NULL);
-#else
-    gps_query(m_gpsdata, "w+x\n");
-#endif
+    gps_stream(&m_gpsdata, WATCH_ENABLE, NULL);
 
     while (!m_abort) {
         Plasma::DataEngine::Data d;
 
-        if (gps_poll(m_gpsdata) != -1) {
+        if (gps_read(&m_gpsdata) > 0) {
             //kDebug() << "poll ok";
-            if (m_gpsdata->online) {
+            if (m_gpsdata.online) {
                 //kDebug() << "online";
-                if (m_gpsdata->status != STATUS_NO_FIX) {
+                if (m_gpsdata.status != STATUS_NO_FIX) {
                     //kDebug() << "fix";
                     d["accuracy"] = 30;
-                    d["latitude"] = QString::number(m_gpsdata->fix.latitude);
-                    d["longitude"] = QString::number(m_gpsdata->fix.longitude);
+                    d["latitude"] = QString::number(m_gpsdata.fix.latitude);
+                    d["longitude"] = QString::number(m_gpsdata.fix.longitude);
                 }
             }
         }
@@ -73,8 +69,9 @@
     : GeolocationProvider(parent, args),
       m_gpsd(0)
 {
-    gps_data_t* gpsdata = gps_open("localhost", DEFAULT_GPSD_PORT);
-    if (gpsdata) {
+    gps_data_t gpsdata;
+
+    if (gps_open("localhost", DEFAULT_GPSD_PORT, &gpsdata) == 0) {
         kDebug() << "gpsd found.";
         m_gpsd = new Gpsd(gpsdata);
         connect(m_gpsd, SIGNAL(dataReady(const Plasma::DataEngine::Data&)),
