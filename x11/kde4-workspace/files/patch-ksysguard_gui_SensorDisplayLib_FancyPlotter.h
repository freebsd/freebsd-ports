* Add a couple variables for the additional functionality in FancyPlotter.cpp
*
--- ksysguard/gui/SensorDisplayLib/FancyPlotter.h.orig	2015-06-26 03:17:21 UTC
+++ ksysguard/gui/SensorDisplayLib/FancyPlotter.h
@@ -52,6 +52,7 @@ class FPSensorProperties : public KSGRD:
     double minValue;
     double lastValue;
     bool isInteger;
+    bool hasDescription;
 
   private:
     QColor mColor;
@@ -104,7 +105,7 @@ class FancyPlotter : public KSGRD::Senso
   private:
     void sendDataToPlotter();
     uint mBeams;
-    
+
     int mNumAnswers;
     /** When we talk to the sensor, it tells us a range.  Record the max here.  equals 0 until we have an answer from it */
     double mSensorReportedMax;
@@ -131,6 +132,7 @@ class FancyPlotter : public KSGRD::Senso
     QLabel *mHeading;
 
     QString mUnit;
+    bool mRealUnits;
 
     QList<SensorToAdd *> mSensorsToAdd;
     QBoxLayout *mLabelLayout;
