--- plugin-sysstat/lxqtsysstat.cpp.orig	2021-05-02 21:18:35 UTC
+++ plugin-sysstat/lxqtsysstat.cpp
@@ -386,10 +386,11 @@ void LXQtSysStatContent::clearLine()
 
 void LXQtSysStatContent::cpuLoadFrequencyUpdate(float user, float nice, float system, float other, float frequencyRate, uint)
 {
-    int y_system = static_cast<int>(system * 100.0 * frequencyRate);
-    int y_user   = static_cast<int>(user   * 100.0 * frequencyRate);
-    int y_nice   = static_cast<int>(nice   * 100.0 * frequencyRate);
-    int y_other  = static_cast<int>(other  * 100.0 * frequencyRate);
+    //On FreeBSD do not multiple with frequencyrate in order to match top
+    int y_system = static_cast<int>(system * 100.0);
+    int y_user   = static_cast<int>(user   * 100.0);
+    int y_nice   = static_cast<int>(nice   * 100.0);
+    int y_other  = static_cast<int>(other  * 100.0);
     int y_freq   = static_cast<int>(         100.0 * frequencyRate);
 
     toolTipInfo(tr("system: %1%<br>user: %2%<br>nice: %3%<br>other: %4%<br>freq: %5%", "CPU tooltip information")
