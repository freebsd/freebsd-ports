--- ./src/wmtaskbar.cc.orig	2009-01-25 09:39:51.000000000 -0500
+++ ./src/wmtaskbar.cc	2009-09-03 16:12:50.000000000 -0400
@@ -458,6 +458,7 @@
 #ifdef CONFIG_APPLET_APM
     if (taskBarShowApm && (access(APMDEV, 0) == 0 ||
                            access("/proc/acpi", 0) == 0 ||
+                           access("/dev/acpi", 0) == 0 ||
 	                   access("/proc/pmu", R_OK|X_OK) == 0))
     {
         fApm = new YApm(this);
