--- eworkpanel/cpumonitor.h.orig	Sat Feb 28 04:46:26 2004
+++ eworkpanel/cpumonitor.h	Sat Feb 28 04:47:10 2004
@@ -3,7 +3,7 @@
 
 #include <config.h>
 
-#if (defined(linux) || defined(HAVE_KSTAT_H))
+#if (defined(linux) || defined(__FreeBSD__) || defined(HAVE_KSTAT_H))
 
 #ifdef HAVE_KSTAT_H
 #include <kstat.h>
