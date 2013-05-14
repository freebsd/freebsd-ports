--- epplets/E-MemWatch.c.orig	2012-09-30 11:38:35.000000000 +0200
+++ epplets/E-MemWatch.c	2013-05-14 18:17:45.000000000 +0200
@@ -1,5 +1,6 @@
 /*
  * Copyright (C) 1999-2000, Michael Jennings
+ *               2008, Pietro Cerutti <gahr@FreeBSD.org> (FreeBSD adaptation)
  *
  * Permission is hereby granted, free of charge, to any person obtaining a copy
  * of this software and associated documentation files (the "Software"), to
@@ -37,6 +38,13 @@
 #include "proc.h"
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <fcntl.h>
+#include <kvm.h>
+#endif
+
 #if 0
 #define D(x) do {printf("%10s | %7d:  [debug] ", __FILE__, __LINE__); printf x; fflush(stdout);} while (0)
 #else
@@ -74,7 +82,7 @@
    used = (unsigned long)mem.used;
    buffers = (unsigned long)mem.buffer;
    cached = (unsigned long)mem.cached;
-#else
+#elif defined(linux)
    FILE               *fp;
 
    if (!(fp = fopen("/proc/meminfo", "r")))
@@ -109,8 +117,20 @@
 	sscanf(buff, "%*s %lu %lu %*u %*u %lu %lu", &total, &used, &buffers,
 	       &cached);
      }
+#elif defined(__FreeBSD__)
+   int pagesize = getpagesize();
+   size_t len = sizeof(used);
+   sysctlbyname("hw.physmem", &total, &len, NULL, 0);
+   sysctlbyname("vm.stats.vm.v_free_count", &free, &len, NULL, 0);
+   sysctlbyname("vfs.bufspace", &buffers, &len, NULL, 0);
+   sysctlbyname("vm.stats.vm.v_cache_count", &cached, &len, NULL, 0);
+
+   cached *= pagesize;
+   free *= pagesize;
 
-#endif /* HAVE_LIBGTOP */
+   used = total - free;
+
+#endif 
 
    used -= (buffers + cached);
    mem_val = (int)((((float)used) / total) * 100.0);
@@ -123,15 +143,15 @@
      }
    else if (used < 1024 * 1024)
      {
-	Esnprintf(buff, sizeof(buff), "M: %luK", used / 1024);
+	Esnprintf(buff, sizeof(buff), "M: %dK", used / 1024);
      }
    else if (used < 1024 * 1024 * 1024)
      {
-	Esnprintf(buff, sizeof(buff), "M: %luM", used / (1024 * 1024));
+	Esnprintf(buff, sizeof(buff), "M: %dM", used / (1024 * 1024));
      }
    else
      {
-	Esnprintf(buff, sizeof(buff), "M: %luG", used / (1024 * 1024 * 1024));
+	Esnprintf(buff, sizeof(buff), "M: %.2lfG", used / (1024.0 * 1024.0 * 1024.0));
      }
    Epplet_change_label(mem_label, buff);
 
@@ -145,7 +165,7 @@
 	used = (unsigned long)swap.used;
      }
    while (swap.total == 0 && swap.used == 0 && check++ < 15);
-#else
+#elif defined(linux)
 
    if (kernel_2_6)
      {
@@ -174,8 +194,23 @@
      }
 
    fclose(fp);
-#endif /* HAVE_LIBGTOP */
-   swap_val = (int)((((float)used) / total) * 100.0);
+#elif defined(__FreeBSD__)
+   kvm_t *k;
+   struct kvm_swap swp;
+   
+   if(!(k = kvm_open(NULL, "/dev/null", NULL, O_RDONLY, "kvm_open"))) {
+      used = 0;
+      total = 1;
+   } else {
+      if(kvm_getswapinfo(k, &swp, 1, 0) != 1) {
+         used = (unsigned long)swp.ksw_used * pagesize;
+         total = (unsigned long)swp.ksw_total * pagesize;
+      }
+      kvm_close(k); 
+   }
+#endif 
+   swap_val = 100. * used / total;
+   printf ("swap_val: %d\n", swap_val);
 
    /*printf ("Swap: %lu %lu %d%%\n", total, used, swap_val); */
 
@@ -273,6 +308,7 @@
 {
 
    int                 prio;
+#ifdef linux
 
    /* check for Kernel 2.6 */
    FILE               *fp;
@@ -295,6 +331,7 @@
 
    fclose(fp);
    /* end check for Kernel 2.6 */
+#endif
 
    atexit(Epplet_cleanup);
    prio = getpriority(PRIO_PROCESS, getpid());
