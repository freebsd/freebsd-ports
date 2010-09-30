--- src/plugins/cpu/cpu.c.orig	2010-02-08 01:37:52.000000000 -0500
+++ src/plugins/cpu/cpu.c	2010-09-24 12:30:27.856886131 -0400
@@ -19,12 +19,24 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
  *
  */
-/*A little bug fixed by Mykola <mykola@2ka.mipt.ru>:) */
+
+/*
+ * A little bug fixed by Mykola <mykola@2ka.mipt.ru> :)
+ * FreeBSD support added by Andreas Wiese <aw@instandbesetzt.net>
+ */
+
 
 #include <string.h>
 #include <sys/time.h>
 #include <time.h>
-#include <sys/sysinfo.h>
+#ifdef __FreeBSD__
+# include <sys/types.h>
+# include <sys/resource.h>
+# include <sys/sysctl.h>
+# include <stdio.h>
+#else
+# include <sys/sysinfo.h>
+#endif
 #include <stdlib.h>
 #include <glib/gi18n.h>
 
@@ -65,6 +77,39 @@
 static int cpu_constructor(Plugin * p, char ** fp);
 static void cpu_destructor(Plugin * p);
 
+#ifdef __FreeBSD__
+static void
+get_procstat(unsigned long *u, unsigned long *n, unsigned long *s,
+    unsigned long *i)
+{
+    static int mib[2] = { -1, -1 }, init = 0, j, realhz;
+    long ct[CPUSTATES];
+
+
+    if(init == 0) {
+      struct clockinfo ci;
+      j = sizeof(ci);
+      sysctlbyname("kern.clockrate", &ci, &j, NULL, 0);
+      realhz = ci.stathz ? ci.stathz : ci.hz;
+
+      j = 2;
+      sysctlnametomib("kern.cp_time", mib, &j);
+
+      init = 1;
+      j = sizeof(ct);
+    }
+
+    sysctl(mib, 2, ct, &j, NULL, 0);
+    *u = ct[CP_USER] / realhz;
+    *n = ct[CP_NICE] / realhz;
+    *s = ct[CP_SYS]  / realhz;
+    *i = ct[CP_IDLE] / realhz;
+
+    return;
+}
+#endif
+
+
 /* Redraw after timer callback or resize. */
 static void redraw_pixmap(CPUPlugin * c)
 {
@@ -99,11 +144,18 @@
     {
         /* Open statistics file and scan out CPU usage. */
         struct cpu_stat cpu;
-        FILE * stat = fopen("/proc/stat", "r");
-        if (stat == NULL)
-            return TRUE;
-        int fscanf_result = fscanf(stat, "cpu %lu %lu %lu %lu", &cpu.u, &cpu.n, &cpu.s, &cpu.i);
-        fclose(stat);
+        FILE * stat;
+
+	#ifdef __FreeBSD__
+	    get_procstat(&cpu.u, &cpu.n, &cpu.s, &cpu.i);
+	    int fscanf_result = 4;
+	#else
+	    stat = fopen("/proc/stat", "r");
+            if (stat == NULL)
+                return TRUE;
+            int fscanf_result = fscanf(stat, "cpu %lu %lu %lu %lu", &cpu.u, &cpu.n, &cpu.s, &cpu.i);
+            fclose(stat);
+	#endif
 
         /* Ensure that fscanf succeeded. */
         if (fscanf_result == 4)
