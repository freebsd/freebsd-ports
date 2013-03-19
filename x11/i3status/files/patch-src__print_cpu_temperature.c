--- ./src/print_cpu_temperature.c.orig	2013-03-19 21:07:05.089386424 +0100
+++ ./src/print_cpu_temperature.c	2013-03-19 21:07:14.249384762 +0100
@@ -14,6 +14,7 @@
 #include <sys/sysctl.h>
 #define TZ_ZEROC 2732
 #define TZ_KELVTOC(x) (((x) - TZ_ZEROC) / 10), abs(((x) - TZ_ZEROC) % 10)
+#define TZ_AVG(x) ((x) - TZ_ZEROC) / 10
 #endif
 
 #if defined(__OpenBSD__)
@@ -80,7 +81,16 @@
                         if (sysctlbyname(path, &sysctl_rslt, &sysctl_size, NULL, 0))
                                 goto error;
 
+                        if (TZ_AVG(sysctl_rslt) >= max_threshold) {
+                                START_COLOR("color_bad");
+                                colorful_output = true;
+                        }
                         outwalk += sprintf(outwalk, "%d.%d", TZ_KELVTOC(sysctl_rslt));
+                        if (colorful_output) {
+                                END_COLOR;
+                                colorful_output = false;
+                        }
+
 #elif defined(__OpenBSD__)
         struct sensordev sensordev;
         struct sensor sensor;
