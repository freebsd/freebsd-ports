--- epplets/E-Cpu.c.orig	Wed Dec 29 06:08:09 1999
+++ epplets/E-Cpu.c	Wed Aug  1 12:10:17 2001
@@ -7,10 +7,23 @@
 #include "config.h"
 #include "epplet.h"
 
-#ifdef HAVE_LIBGTOP
+#ifdef __FreeBSD__
+
+#include <sys/sysctl.h>
+#include <sys/dkstat.h>
+
+#ifndef KERN_CP_TIME
+#define KERN_CP_TIME 106
+#endif
+
+int cpu_old[CPUSTATES];
+
+#elif defined(HAVE_LIBGTOP)
+
 #include <glibtop.h>
 #include <glibtop/cpu.h>
 #include "proc.h"
+
 #endif
 
 int                 cpus = 0;
@@ -201,7 +214,33 @@
 static void
 cb_timer(void *data)
 {
-#ifdef HAVE_LIBGTOP
+#ifdef __FreeBSD__
+
+	int cpu_new[CPUSTATES];
+	int i, total, mib[2];
+	size_t cpu_size;
+	double val;
+	
+	mib[0] = CTL_KERN;
+	mib[1] = KERN_CP_TIME;
+	cpu_size = sizeof(cpu_new);
+
+	if(sysctl(mib, 2, cpu_new, &cpu_size, NULL, 0) == 0)
+	{
+		total=0;
+		for(i=0;i<CPUSTATES;i++)
+			total += cpu_new[i] - cpu_old[i];
+			
+		val = 100.00 - (double)(cpu_new[CP_IDLE]-cpu_old[CP_IDLE])/total*100;	
+
+		for(i=0;i<CPUSTATES;i++)
+			cpu_old[i] = cpu_new[i];
+
+		for(i=0;i<cpus;i++)
+			prev_val[i] = load_val[i] = val;
+	}
+
+#elif HAVE_LIBGTOP
 
     glibtop_cpu cpu;
     double val, val2;
@@ -322,13 +361,27 @@
 static int
 count_cpus(void)
 {
-#ifdef HAVE_LIBGTOP
+#ifdef __FreeBSD__
+
+	int ncpu, mib[2];
+	size_t size;
+	
+	mib[0] = CTL_HW;
+	mib[1] = HW_NCPU;
+	size = sizeof(ncpu);
+	
+	if(sysctl(mib, 2, &ncpu, &size, NULL, 0) == -1)
+		return 1;
+	
+	return ncpu;
+
+#elif defined(HAVE_LIBGTOP)
   int i,c = 0;
   int bits;
   glibtop_cpu cpu;
 
     glibtop_get_cpu (&cpu);
-    bits= (int)cpu.xcpu_flags;
+    bits= (int)cpu.flags;
     for (i=0; i<GLIBTOP_NCPU; i++) {
       c += bits&1;
       /*      printf ("%d: %o - %d\n",i,bits,c ); */
