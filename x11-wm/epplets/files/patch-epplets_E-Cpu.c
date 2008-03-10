--- epplets/E-Cpu.c.orig	2007-03-16 20:52:25.000000000 +0100
+++ epplets/E-Cpu.c	2008-01-24 13:40:28.000000000 +0100
@@ -1,3 +1,7 @@
+/*
+ * Copyright (C) 2008, Pietro Cerutti <gahr@FreeBSD.org> (FreeBSD adaptation)
+ */
+
 #include <stdio.h>
 #include <sys/time.h>
 #include <sys/resource.h>
@@ -13,6 +17,12 @@
 #include "proc.h"
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <sys/param.h>
+#endif
+
 int                 cpus = 0;
 double             *prev_val = NULL;
 double             *prev_val_nice = NULL;
@@ -76,7 +86,7 @@
 #define VSPREAD  160
 #define RESIDUAL 75
 
-#define MAX      255
+#define FLAME_MAX      255
 
 static void
 flame_col(int r1, int g1, int b1, int r2, int g2, int b2, int r3, int g3,
@@ -133,7 +143,7 @@
 	hspread[x] = HSPREAD + (load_val[(x * cpus) / 40] / 50);
 	residual[x] = RESIDUAL + (load_val[(x * cpus) / 40] / 50);
 	ptr[x] = (rand() % ((load_val[(x * cpus) / 40]) + 155));
-	if (ptr[x] > MAX)
+	if (ptr[x] > FLAME_MAX)
 	   ptr[x] = 0;
 	else if (ptr[x] < 0)
 	   ptr[x] = 0;
@@ -163,14 +173,14 @@
 	     val3 = (ptr[x] * residual[x]) >> 8;
 
 	     ptr[x - 1] += val2;
-	     if (ptr[x - 1] > MAX)
-		ptr[x - 1] = MAX;
+	     if (ptr[x - 1] > FLAME_MAX)
+		ptr[x - 1] = FLAME_MAX;
 	     ptr[x - 40] += val1;
-	     if (ptr[x - 40] > MAX)
-		ptr[x - 40] = MAX;
+	     if (ptr[x - 40] > FLAME_MAX)
+		ptr[x - 40] = FLAME_MAX;
 	     ptr[x + 1] += val2;
-	     if (ptr[x + 1] > MAX)
-		ptr[x + 1] = MAX;
+	     if (ptr[x + 1] > FLAME_MAX)
+		ptr[x + 1] = FLAME_MAX;
 	     ptr[x] = val3;
 	  }
      }
@@ -204,11 +214,12 @@
 static void
 cb_timer(void *data)
 {
-#ifdef HAVE_LIBGTOP
 
+   double val, val2, val_nice, val2_nice;
+   int i;
+
+#ifdef HAVE_LIBGTOP
    glibtop_cpu         cpu;
-   double              val, val2;
-   int                 i;
 
    glibtop_get_cpu(&cpu);
 
@@ -226,14 +237,37 @@
 	/*      printf ("CPU%d: %ld : %ld : %d : %d\n",i, val, prev_val[i], val2, load_val[i]); */
      }
 
-#else
+   goto end;
+#endif
 
+#ifdef __FreeBSD__
+   size_t len;
+   int max_cpus;
+
+   len = sizeof(max_cpus);
+
+   if(sysctlbyname("kern.smp.maxcpus", &max_cpus, &len, NULL, 0)) {
+      perror("Couldn't get maximum number of CPUs");
+      exit(EXIT_FAILURE);
+   }
+   long cp_time[sizeof(long) * max_cpus * CPUSTATES + 1];
+
+   len = sizeof(cp_time);
+
+   if(sysctlbyname("kern.cp_times", &cp_time, &len, NULL, 0)) {
+      perror("Couldn't retrieve CPU states");
+      exit(EXIT_FAILURE);
+   }
+
+   for(i=0; i<cpus; i++) {
+      val = cp_time[0*CPUSTATES];
+      val_nice = cp_time[1*CPUSTATES];
+   }
+#else
    static FILE        *f;
-   int                 i;
 
    f = fopen("/proc/stat", "r");
-   if (f)
-     {
+   if (!f) exit(EXIT_FAILURE);
 	char                s[256];
 
 	if (cpus > 1)
@@ -242,40 +276,45 @@
 	  {
 	     char                sUserCPU[64];
 	     char                sNiceCPU[64];
-	     double              val, val2, val_nice, val2_nice;
 
 	     fgets(s, 255, f);
 	     sscanf(s, "%*s %s %s %*s %*s", sUserCPU, sNiceCPU);
 
 	     val = atof(sUserCPU);
 	     val_nice = atof(sNiceCPU);
-
-	     val2 = val - prev_val[i];
-	     prev_val[i] = val;
-	     val2 *= 10;
-	     if (val2 > 100)
-		val2 = 100;
-
-	     val2_nice = val_nice - prev_val_nice[i];
-	     prev_val_nice[i] = val_nice;
-	     val2_nice *= 10;
-	     if (val2_nice > 100)
-		val2_nice = 100;
-
-	     if (include_nice)
-		load_val[i] = val2 + val2_nice;
-	     else
-		load_val[i] = val2;
-
-	     if (load_val[i] > 100)
-		load_val[i] = 100;
-
-	  }
-	fclose(f);
      }
 
+   fclose(f);
 #endif
 
+   for(i=0; i<cpus; i++) {
+      if(prev_val[i] == 0)
+         prev_val[i] = val;
+      val2 = val - prev_val[i];
+      prev_val[i] = val;
+      val2 *= 10;
+      if (val2 > 100)
+         val2 = 100;
+
+      if(prev_val_nice[i] == 0)
+         prev_val_nice[i] = val_nice;
+      val2_nice = val_nice - prev_val_nice[i];
+	   prev_val_nice[i] = val_nice;
+	   val2_nice *= 10;
+	   if (val2_nice > 100)
+		   val2_nice = 100;
+
+	   if (include_nice)
+		   load_val[i] = val2 + val2_nice;
+	   else
+		   load_val[i] = val2;
+
+	   if (load_val[i] > 100)
+		   load_val[i] = 100;
+   }
+
+end:
+
    draw_flame();
    Epplet_paste_buf(buf, win, 0, 0);
    Epplet_timer(cb_timer, NULL, 0.1, "TIMER");
@@ -375,7 +414,22 @@
    /* printf ("CPUs: %d\n", c); */
 
    return c;
-#else
+#endif
+
+#ifdef __FreeBSD__
+   int mib[2];
+   int nof_cpus;
+   size_t len = sizeof(nof_cpus);;
+
+   mib[0] = CTL_HW;
+   mib[1] = HW_NCPU;
+   if(sysctl(mib, 2, &nof_cpus, &len, NULL, 0) == -1) {
+      perror("Couldn't retrieve the number of CPUs: %s");
+      exit(EXIT_FAILURE);
+   }
+   return (nof_cpus);
+#endif
+
    FILE               *f;
    char                s[256];
 
@@ -403,7 +457,6 @@
 	return count;
      }
    exit(1);
-#endif
 }
 
 static void
