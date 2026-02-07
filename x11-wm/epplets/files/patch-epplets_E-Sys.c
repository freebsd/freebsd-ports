--- epplets/E-Sys.c.orig	2008-01-24 19:41:11.000000000 +0100
+++ epplets/E-Sys.c	2008-01-24 19:54:23.000000000 +0100
@@ -1,5 +1,6 @@
 /*
  * Copyright (C) 1999-2000, Michael Jennings
+ *               2008, Pietro Cerutti <gahr@FreeBSD.org> (FreeBSD adaptation)
  *
  * Permission is hereby granted, free of charge, to any person obtaining a copy
  * of this software and associated documentation files (the "Software"), to
@@ -36,6 +37,12 @@
 #include "proc.h"
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#define USECS_PER_SEC 1000;
+#endif
+
 #if 0
 #  define D(x) do {printf("%10s | %7d:  [debug] ", __FILE__, __LINE__); printf x; fflush(stdout);} while (0)
 #else
@@ -67,7 +74,7 @@
    glibtop_get_uptime(&uptime);
    secs = (unsigned long)uptime.uptime;
 
-#else
+#elif defined(linux)
 
    FILE               *fp;
 
@@ -81,6 +88,15 @@
    secs = (unsigned long)total_secs;
    fclose(fp);
 
+#elif defined(__FreeBSD__)
+   struct timeval bt;
+   size_t len = sizeof(bt);
+   time_t base, now;
+   int mib[] = {CTL_KERN, KERN_BOOTTIME};
+   sysctl(mib, 2, &bt, &len, NULL, 0);
+   time(&now);
+   base = now - bt.tv_sec + 30;
+   secs = base;
 #endif
 
    days = secs / 86400;
@@ -89,11 +105,8 @@
    secs %= 3600;
    mins = secs / 60;
    secs %= 60;
-   if (secs == 0)
-     {
-	secs = 60;
-     }
-   delay = (double)secs;
+
+   delay = 60 - (double)secs;
 
    Esnprintf(buff, sizeof(buff), "%lu days", days);
    Epplet_change_label(label2, buff);
