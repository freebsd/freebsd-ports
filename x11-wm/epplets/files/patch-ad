--- epplets/E-Load.c.orig	Fri Nov 19 13:46:24 1999
+++ epplets/E-Load.c	Fri Aug  3 18:45:55 2001
@@ -1,11 +1,17 @@
 #include "config.h"
 #include "epplet.h"
 
-#ifdef HAVE_LIBGTOP
+#ifdef __FreeBSD__
+
+#include <sys/sysctl.h>
+
+#elif defined(HAVE_LIBGTOP)
+
 #include <glibtop.h>
 #include <glibtop/loadavg.h>
 #include <glibtop/cpu.h>
 #include "proc.h"
+
 #endif
 
 int cpus = 0;
@@ -20,7 +26,22 @@
 static void
 cb_timer(void *data)
 {
-#ifdef HAVE_LIBGTOP
+#ifdef __FreeBSD__
+
+	double val;
+	
+	if(getloadavg(&val, 1) == -1)
+		return;
+	
+	val *= 20;
+	
+	if(val > 100)
+		val = 100;
+		
+	load_val[0] = val;
+	Epplet_gadget_data_changed(load[0]);
+	
+#elif defined(HAVE_LIBGTOP)
 
 /* libgtop only handles total load, not per-CPU load */
 
@@ -89,13 +110,27 @@
 int
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
+#elif HAVE_LIBGTOP
   int i,c = 0;
   int bits;
   glibtop_cpu cpu;
 
     glibtop_get_cpu (&cpu);
-    bits= (int)cpu.xcpu_flags;
+    bits= (int)cpu.flags;
     for (i=0; i<GLIBTOP_NCPU; i++) {
       c += bits&1;
       /*      printf ("%d: %o - %d\n",i,bits,c ); */
