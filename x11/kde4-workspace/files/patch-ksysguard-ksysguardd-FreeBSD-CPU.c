--- ksysguard/ksysguardd/FreeBSD/CPU.c.orig	Sat Nov  8 15:40:15 2003
+++ ksysguard/ksysguardd/FreeBSD/CPU.c	Sat Nov  8 15:16:40 2003
@@ -49,6 +49,8 @@
 long cp_diff[CPUSTATES];
 int cpu_states[CPUSTATES];

+size_t cp_time_len = sizeof(cp_time);
+
 void
 initCpuInfo(struct SensorModul* sm)
 {
@@ -73,7 +75,7 @@
 int
 updateCpuInfo(void)
 {
-        sysctlbyname("kern.cp_time", &cp_time, sizeof(cp_time), NULL, 0);
+        sysctlbyname("kern.cp_time", &cp_time, &cp_time_len, NULL, 0);
         percentages(CPUSTATES, cpu_states, cp_time, cp_old, cp_diff);
 	return (0);
 }

