--- plugins/cpu.c~	Tue May 16 19:23:18 2006
+++ plugins/cpu.c	Tue May 16 19:00:07 2006
@@ -18,14 +18,24 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
  * 
  */
-/*A little bug fixed by Mykola <mykola@2ka.mipt.ru>:) */
+/*
+ * A little bug fixed by Mykola <mykola@2ka.mipt.ru> :)
+ * FreeBSD support added by Andreas Wiese <aw@instandbesetzt.net>
+ */
 
 
 #include <string.h>
 #include <sys/time.h>
 #include <time.h>
-#include <sys/sysinfo.h>
+#ifdef __FreeBSD__
+# include <sys/types.h>
+# include <sys/resource.h>
+# include <sys/sysctl.h>
+#else
+# include <sys/sysinfo.h>
+#endif
 #include <stdlib.h>
+#include <stdio.h>
 
 #include "plugin.h"
 #include "panel.h"
@@ -60,6 +70,37 @@
     struct cpu_stat cpu_anterior;
 } cpu_t;
 
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
+	struct clockinfo ci;
+	j = sizeof(ci);
+	sysctlbyname("kern.clockrate", &ci, &j, NULL, 0);
+	realhz = ci.stathz ? ci.stathz : ci.hz;
+
+	j = 2;
+	sysctlnametomib("kern.cp_time", mib, &j);
+
+	init = 1;
+	j = sizeof(ct);
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
 
 static int
 cpu_update(cpu_t *c)
@@ -67,18 +108,24 @@
     int cpu_u=0, cpu_s=0, cpu_n=0, cpu_i=100;
     unsigned int i;
     struct cpu_stat cpu, cpu_r;
+#ifndef __FreeBSD__
     FILE *stat;
+#endif
     float total;
     
     ENTER;
     if(!c->pixmap)
         RET(TRUE); 
      
+#ifdef __FreeBSD__
+    get_procstat(&cpu.u, &cpu.n, &cpu.s, &cpu.i);
+#else
     stat = fopen("/proc/stat", "r");
     if(!stat)
         RET(TRUE);
     fscanf(stat, "cpu %lu %lu %lu %lu", &cpu.u, &cpu.n, &cpu.s, &cpu.i);
     fclose(stat);
+#endif
 
     cpu_r.u = cpu.u - c->cpu_anterior.u;
     cpu_r.n = cpu.n - c->cpu_anterior.n;
