--- eworkpanel/cpumonitor.cpp.orig	Sat Feb 28 04:46:23 2004
+++ eworkpanel/cpumonitor.cpp	Sat Feb 28 04:46:55 2004
@@ -26,7 +26,7 @@
 #include <kstat.h>
 #endif
 
-#if (defined(linux) || defined(HAVE_KSTAT_H))
+#if (defined(linux) || defined(__FreeBSD__) || defined(HAVE_KSTAT_H))
 
 #define UPDATE_INTERVAL .5f
 
