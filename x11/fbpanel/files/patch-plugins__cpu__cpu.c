--- ./plugins/cpu/cpu.c.orig	2010-03-07 00:14:04.000000000 -0800
+++ ./plugins/cpu/cpu.c	2013-11-04 01:56:23.388313800 +0400
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
@@ -84,6 +102,59 @@
     RET(TRUE);
 
 }
+#elif defined __FreeBSD__
+static int
+cpu_get_load(cpu_priv * c)
+{
+	static int	mib[2] = {-1, -1}, init = 0, j;
+	long		ct[CPUSTATES];
+
+	gfloat		a      , b;
+	struct cpu_stat	cpu;
+	float		total;
+	gchar		buf[40];
+
+	ENTER;
+	total = 0;
+
+	if (init == 0) {
+		j = 2;
+		if (sysctlnametomib("kern.cp_time", mib, &j) == -1) {
+			DBG("Couldn't get mib for kern.cp_time");
+			RET(FALSE);
+		}
+		c->cpu_prev.u = 0;
+		c->cpu_prev.n = 0;
+		c->cpu_prev.s = 0;
+		c->cpu_prev.i = 0;
+		c->cpu_prev.w = 0;
+		init = 1;
+		j = sizeof(ct);
+	}
+	if (sysctl(mib, 2, ct, &j, NULL, 0) == -1) {
+		DBG("Couldn't get cpu stats");
+		RET(FALSE);
+	}
+
+	a = ct[CP_USER] + ct[CP_NICE] + ct[CP_SYS] + ct[CP_INTR] -
+            (c->cpu_prev.u + c->cpu_prev.n + c->cpu_prev.s + c->cpu_prev.i);
+	b = a + ct[CP_IDLE] - c->cpu_prev.w;
+	total = b ? (float)a / b : 1.0;
+
+	c->cpu_prev.u = ct[CP_USER];
+	c->cpu_prev.n = ct[CP_NICE];
+	c->cpu_prev.s = ct[CP_SYS] ;
+	c->cpu_prev.i = ct[CP_INTR];
+	c->cpu_prev.w = ct[CP_IDLE];
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
