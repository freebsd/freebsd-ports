--- plugins/monitors/monitors.c.orig	2016-11-19 18:28:43 UTC
+++ plugins/monitors/monitors.c
@@ -72,6 +72,12 @@
  */
 
 #include <stdlib.h>
+#if defined(__DragonFly__) || (__FreeBSD__)
+#include <unistd.h>
+#include <sys/resource.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
 #include <glib/gi18n.h>
 #include <errno.h>
 #include <libfm/fm-gtk.h>
@@ -221,20 +227,46 @@ monitor_set_foreground_color(MonitorsPlu
 /******************************************************************************
  *                                 CPU monitor                                *
  ******************************************************************************/
-typedef unsigned long long CPUTick;/* Value from /proc/stat                   */
 typedef float CPUSample;	   /* Saved CPU utilization value as 0.0..1.0 */
 
+#if defined(__linux__)
+typedef unsigned long long CPUTick;/* Value from /proc/stat                   */
+
 struct cpu_stat {
     CPUTick u, n, s, i;		  /* User, nice, system, idle */
 };
+#elif defined(__DragonFly__) || (__FreeBSD__)
+typedef glong CPUTick;
+
+struct cpu_stat {
+    CPUTick u, n, s, intr, i;
+};
+
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
 
 static gboolean
 cpu_update(Monitor * c)
 {
+#if defined(__linux__)
     static struct cpu_stat previous_cpu_stat = { 0, 0, 0, 0 };
+#elif defined(__DragonFly__) || (__FreeBSD__)
+    static struct cpu_stat previous_cpu_stat = { 0, 0, 0, 0, 0 };
+#endif
 
     if ((c->stats != NULL) && (c->pixmap != NULL))
     {
+#if defined(__linux__)
         /* Open statistics file and scan out CPU usage. */
         struct cpu_stat cpu;
         FILE * stat = fopen("/proc/stat", "r");
@@ -269,6 +301,48 @@ cpu_update(Monitor * c)
             /* Redraw with the new sample. */
             redraw_pixmap(c);
         }
+#elif defined(__DragonFly__) || (__FreeBSD__)
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
+            cpu_delta.u = cpu.u - previous_cpu_stat.u;
+            cpu_delta.n = cpu.n - previous_cpu_stat.n;
+            cpu_delta.s = cpu.s - previous_cpu_stat.s;
+            cpu_delta.intr = cpu.intr - previous_cpu_stat.intr;
+            cpu_delta.i = cpu.i - previous_cpu_stat.i;
+
+            memcpy(&previous_cpu_stat, &cpu, sizeof(struct cpu_stat));
+
+            float cpu_used = cpu_delta.u + cpu_delta.n;
+            float cpu_total = cpu_used + cpu_delta.s + cpu_delta.intr + cpu_delta.i;
+            c->stats[c->ring_cursor] = cpu_used / cpu_total;
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
@@ -294,11 +368,38 @@ cpu_tooltip_update (Monitor *m)
 /******************************************************************************
  *                               RAM Monitor                                  *
  ******************************************************************************/
+#if defined(__DragonFly__) || (__FreeBSD__)
+static glong
+mem_get_by_bytes(const gchar *name)
+{
+    glong buf;
+    gsize len = sizeof(glong);
+
+    if (sysctlbyname(name, &buf, &len, NULL, 0) < 0)
+        return 0;
+    else
+        return buf;
+}
+
+static glong
+mem_get_by_pages(const gchar *name)
+{
+    glong res = 0;
+
+    res = mem_get_by_bytes(name);
+    if (res > 0)
+        res = res * getpagesize();
+
+    return res;
+}
+#endif
+
 static gboolean
 mem_update(Monitor * m)
 {
     ENTER;
 
+#if defined(__linux__)
     FILE *meminfo;
     char buf[80];
     long int mem_total = 0;
@@ -343,6 +444,17 @@ mem_update(Monitor * m)
                   "readmask %x", readmask);
         RET(FALSE);
     }
+#elif defined(__DragonFly__) || (__FreeBSD__)
+    if (!m->stats || !m->pixmap)
+        RET(TRUE);
+
+    glong mem_total, mem_free, mem_buffers, mem_cached;
+
+    mem_total = mem_get_by_bytes("hw.physmem");
+    mem_free = mem_get_by_pages("vm.stats.vm.v_free_count");
+    mem_buffers = mem_get_by_bytes("vfs.bufspace");
+    mem_cached = mem_get_by_pages("vm.stats.vm.v_inactive_count");
+#endif
 
     m->total = mem_total;
 
