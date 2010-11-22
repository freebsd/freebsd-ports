--- ./plugins/cpu/cpu.c.orig	2010-03-07 00:14:04.000000000 -0800
+++ ./plugins/cpu/cpu.c	2010-11-17 11:06:07.000000000 -0800
@@ -18,9 +18,20 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
  *
  */
-/*A little bug fixed by Mykola <mykola@2ka.mipt.ru>:) */
+
+/*
+ * A little bug fixed by Mykola <mykola@2ka.mipt.ru>:) 
+ * FreeBSD support added by Andreas Wiese <aw@instandbesetzt.net>
+ */
 
 
+#if defined __FreeBSD__
+#include <sys/types.h>
+#include <sys/time.h>
+#include <sys/resource.h>
+#include <sys/sysctl.h>
+#include <stdio.h>
+#endif
 
 #include "misc.h"
 #include "../chart/chart.h"
@@ -29,9 +40,16 @@
 #include "dbg.h"
 
 /* cpu.c */
+#if defined __FreeBSD__
+struct cpu_stat {
+    gulong u, n, s, i; // user, nice, system, idle
+};
+#else
 struct cpu_stat {
     gulong u, n, s, i, w; // user, nice, system, idle, wait
 };
+#endif
+
 
 typedef struct {
     chart_priv chart;
@@ -84,6 +102,65 @@
     RET(TRUE);
 
 }
+#elif defined __FreeBSD__
+static int
+cpu_get_load(cpu_priv * c)
+{
+	static int	mib[2] = {-1, -1}, init = 0, j, realhz;
+	long		ct[CPUSTATES];
+
+	gfloat		a      , b;
+	struct cpu_stat	cpu, cpu_diff;
+	float		total;
+	gchar		buf[40];
+
+	ENTER;
+	total = 0;
+
+	if (init == 0) {
+		struct clockinfo ci;
+		j = sizeof(ci);
+		if (sysctlbyname("kern.clockrate", &ci, &j, NULL, 0) == -1) {
+			DBG("Couldn't get kern.clockrate");
+			RET(FALSE);
+		} else
+			realhz = ci.stathz ? ci.stathz : ci.hz;
+
+		j = 2;
+		if (sysctlnametomib("kern.cp_time", mib, &j) == -1) {
+			DBG("Couldn't get mib for kern.cp_time");
+			RET(FALSE);
+		}
+		init = 1;
+		j = sizeof(ct);
+	}
+	if (sysctl(mib, 2, ct, &j, NULL, 0) == -1) {
+		DBG("Couldn't get cpu stats");
+		RET(FALSE);
+	}
+	cpu.u = ct[CP_USER] / realhz;
+	cpu.n = ct[CP_NICE] / realhz;
+	cpu.s = ct[CP_SYS] / realhz;
+	cpu.i = ct[CP_IDLE] / realhz;
+
+	cpu_diff.u = cpu.u - c->cpu_prev.u;
+	cpu_diff.n = cpu.n - c->cpu_prev.n;
+	cpu_diff.s = cpu.s - c->cpu_prev.s;
+	cpu_diff.i = cpu.i - c->cpu_prev.i;
+	c->cpu_prev = cpu;
+
+	a = cpu_diff.u + cpu_diff.n + cpu_diff.s;
+	b = a + cpu_diff.i;
+	total = b ? a / b : 1.0;
+
+end:
+	DBG("total=%f a=%f b=%f\n", total, a, b);
+	g_snprintf(buf, sizeof(buf), "<b>Cpu:</b> %d%%", (int)(total * 100));
+	gtk_widget_set_tooltip_markup(((plugin_instance *) c)->pwid, buf);
+	k->add_tick(&c->chart, &total);
+	RET(TRUE);
+
+}
 #else
 static int
 cpu_get_load(cpu_priv *c)
