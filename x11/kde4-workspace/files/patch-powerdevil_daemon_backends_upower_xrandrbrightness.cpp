--- powerdevil/daemon/backends/upower/xrandrbrightness.cpp.orig	2015-06-26 03:17:21 UTC
+++ powerdevil/daemon/backends/upower/xrandrbrightness.cpp
@@ -62,6 +62,9 @@ XRandrBrightness::XRandrBrightness()
         qWarning("No available Randr resources");
         return;
     }
+
+    if (brightness() == -1)
+	m_resources = 0;
 }
 
 XRandrBrightness::~XRandrBrightness()
@@ -89,7 +92,7 @@ bool XRandrBrightness::isSupported() con
 
 float XRandrBrightness::brightness() const
 {
-    float result = 0;
+    float result = -1;
 
     if (!m_resources)
         return result;
