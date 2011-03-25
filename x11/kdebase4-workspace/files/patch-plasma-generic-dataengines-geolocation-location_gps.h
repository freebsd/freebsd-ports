--- plasma/generic/dataengines/geolocation/location_gps.h.orig	2011-03-23 00:37:50.000000000 +0300
+++ plasma/generic/dataengines/geolocation/location_gps.h	2011-03-23 00:41:05.000000000 +0300
@@ -29,7 +29,7 @@
 {
     Q_OBJECT
 public:
-    Gpsd(gps_data_t* gpsdata);
+    Gpsd(gps_data_t gpsdata);
     virtual ~Gpsd();
 
     void update();
@@ -41,7 +41,7 @@
     virtual void run();
 
 private:
-    gps_data_t* m_gpsdata;
+    gps_data_t m_gpsdata;
     QMutex m_mutex;
     QWaitCondition m_condition;
     bool m_abort;
