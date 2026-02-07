--- epplets/E-Load.c.orig	2006-04-16 00:32:42.000000000 +0200
+++ epplets/E-Load.c	2008-04-14 13:14:29.000000000 +0200
@@ -8,6 +8,12 @@
 #include "proc.h"
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <sys/resource.h>
+#endif
+
 int                 cpus = 0;
 double             *prev_val = NULL;
 int                *load_val = NULL;
@@ -20,13 +26,15 @@
 static void
 cb_timer(void *data)
 {
-#ifdef HAVE_LIBGTOP
 
-/* libgtop only handles total load, not per-CPU load */
+   int i;
+   double              val, val2;
+
+#if defined(HAVE_LIBGTOP)
+
+   /* libgtop only handles total load, not per-CPU load */
 
    glibtop_loadavg     loadavg;
-   double              val, val2;
-   int                 i;
 
    glibtop_get_loadavg(&loadavg);
    val2 = loadavg.loadavg[0];
@@ -39,10 +47,27 @@
    load_val[0] = val2;
    Epplet_gadget_data_changed(load[0]);
 
+#elif defined(__FreeBSD__)
+
+   long cp_time[cpus][CPUSTATES]; 
+   size_t len = sizeof(cp_time);
+
+   sysctlbyname((cpus > 1) ? "kern.cp_times" : "kern.cp_time", cp_time, &len, NULL, 0);
+
+   for(i=0; i<cpus; i++)
+   {
+      val = cp_time[i][0];
+      val2 = val - prev_val[i];
+      prev_val[i] = val;
+      val2 *= 3;
+      if(val2 > 100) val2 = 100;
+      load_val[i] = val2;
+      Epplet_gadget_data_changed(load[i]);
+   }
+
 #else
 
    static FILE        *f;
-   int                 i;
 
    f = fopen("/proc/stat", "r");
    if (f)
@@ -54,7 +79,6 @@
 	for (i = 0; i < cpus; i++)
 	  {
 	     char                ss[64];
-	     double              val, val2;
 
 	     fgets(s, 255, f);
 	     sscanf(s, "%*s %s %*s %*s %*s", ss);
@@ -89,7 +113,8 @@
 int
 count_cpus(void)
 {
-#ifdef HAVE_LIBGTOP
+
+#if defined(HAVE_LIBGTOP)
    int                 i, c = 0;
    int                 bits;
    glibtop_cpu         cpu;
@@ -104,8 +129,17 @@
      }
    /* printf ("CPUs: %d\n", c); */
 
-   return c;
+#elif defined(__FreeBSD__)
+
+   int mib[2];
+   int c;
+   size_t len = sizeof(c);
+   mib[0] = CTL_HW;
+   mib[1] = HW_NCPU;
+   sysctl(mib, 2, &c, &len, NULL, 0);
+
 #else
+
    FILE               *f;
    char                s[256];
 
@@ -130,10 +164,11 @@
 	if (count > 1)
 	   count--;
 	fclose(f);
-	return count;
      }
-   exit(1);
+   else
+      exit(1);
 #endif
+   return (c);
 }
 
 int
