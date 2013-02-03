--- ./powerdevil/daemon/backends/upower/xrandrbrightness.cpp.orig	2012-11-30 08:24:40.000000000 +0100
+++ ./powerdevil/daemon/backends/upower/xrandrbrightness.cpp	2013-01-22 20:44:13.303230302 +0100
@@ -69,6 +69,9 @@
         qWarning("No available Randr resources");
         return;
     }
+
+    if (brightness() == -1)
+	m_resources = 0;
 }
 
 XRandrBrightness::~XRandrBrightness()
@@ -85,7 +88,7 @@
 
 float XRandrBrightness::brightness() const
 {
-    float result = 0;
+    float result = -1;
 
     if (!m_resources)
         return result;
