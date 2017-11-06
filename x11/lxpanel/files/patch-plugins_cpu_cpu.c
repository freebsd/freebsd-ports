--- plugins/cpu/cpu.c.orig	2016-11-19 18:28:43 UTC
+++ plugins/cpu/cpu.c
@@ -35,8 +35,15 @@
 #include <string.h>
 #include <sys/time.h>
 #include <time.h>
+#if defined(__linux__)
 #include <sys/sysinfo.h>
+#endif
 #include <stdlib.h>
+#if defined(__DragonFly__) || (__FreeBSD__)
+#include <sys/resource.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
 #include <glib/gi18n.h>
 
 #include "plugin.h"
@@ -46,12 +53,22 @@
 
 /* #include "../../dbg.h" */
 
-typedef unsigned long long CPUTick;		/* Value from /proc/stat */
 typedef float CPUSample;			/* Saved CPU utilization value as 0.0..1.0 */
 
+#if defined(__linux__)
+typedef unsigned long long CPUTick;		/* Value from /proc/stat */
+
 struct cpu_stat {
     CPUTick u, n, s, i;				/* User, nice, system, idle */
 };
+#elif defined(__DragonFly__) || (__FreeBSD__)
+typedef glong CPUTick;
+
+struct cpu_stat {
+    CPUTick u, n, s, intr, i;
+};
+#endif
+
 
 /* Private context for CPU plugin. */
 typedef struct {
@@ -116,6 +133,20 @@ static void redraw_pixmap(CPUPlugin * c)
     gtk_widget_queue_draw(c->da);
 }
 
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+static gint cpu_nb(void)
+{
+    static gint mib[] = { CTL_HW, HW_NCPU };
+    gint res;
+    size_t len = sizeof(gint);
+
+    if (sysctl(mib, 2, &res, &len, NULL, 0) < 0)
+        return 0;
+    else
+        return res;
+}
+#endif
+
 /* Periodic timer callback. */
 static gboolean cpu_update(CPUPlugin * c)
 {
@@ -123,6 +154,7 @@ static gboolean cpu_update(CPUPlugin * c
         return FALSE;
     if ((c->stats_cpu != NULL) && (c->pixmap != NULL))
     {
+#if defined(__linux__)
         /* Open statistics file and scan out CPU usage. */
         struct cpu_stat cpu;
         FILE * stat = fopen("/proc/stat", "r");
@@ -155,6 +187,48 @@ static gboolean cpu_update(CPUPlugin * c
             /* Redraw with the new sample. */
             redraw_pixmap(c);
         }
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
+        size_t cp_size = sizeof(glong) * CPUSTATES * cpu_nb();
+        glong *cp_times = malloc(cp_size);
+
+        if (sysctlbyname("kern.cp_times", cp_times, &cp_size, NULL, 0) < 0)
+        {
+            g_free(cp_times);
+            return FALSE;
+        }
+        else
+        {
+            struct cpu_stat cpu;
+            struct cpu_stat cpu_delta;
+
+            cpu.u = cp_times[CP_USER];
+            cpu.n = cp_times[CP_NICE];
+            cpu.s = cp_times[CP_SYS];
+            cpu.intr = cp_times[CP_INTR];
+            cpu.i = cp_times[CP_IDLE];
+
+            g_free(cp_times);
+
+            /* Compute delta from previous statistics. */
+            cpu_delta.u = cpu.u - c->previous_cpu_stat.u;
+            cpu_delta.n = cpu.n - c->previous_cpu_stat.n;
+            cpu_delta.s = cpu.s - c->previous_cpu_stat.s;
+            cpu_delta.intr = cpu.intr - c->previous_cpu_stat.intr;
+            cpu_delta.i = cpu.i - c->previous_cpu_stat.i;
+
+            memcpy(&c->previous_cpu_stat, &cpu, sizeof(struct cpu_stat));
+
+            float cpu_used = cpu_delta.u + cpu_delta.n;
+            float cpu_total = cpu_used + cpu_delta.s + cpu_delta.intr + cpu_delta.i;
+            c->stats_cpu[c->ring_cursor] = cpu_used / cpu_total;
+            c->ring_cursor += 1;
+            if (c->ring_cursor >= c->pixmap_width)
+                c->ring_cursor = 0;
+
+            /* Redraw with the new sample. */
+            redraw_pixmap(c);
+        }
+#endif
     }
     return TRUE;
 }
