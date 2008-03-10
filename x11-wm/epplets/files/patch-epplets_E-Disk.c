--- epplets/E-Disk.c.orig	2008-03-10 07:54:22.000000000 +0100
+++ epplets/E-Disk.c	2008-03-10 08:33:28.000000000 +0100
@@ -1,5 +1,6 @@
 /*
  * Copyright (C) 1999-2005, Michael Jennings
+ *               2008, Pietro Cerutti <gahr@FreeBSD.org> (FreeBSD adaptation)
  *
  * Permission is hereby granted, free of charge, to any person obtaining a copy
  * of this software and associated documentation files (the "Software"), to
@@ -29,6 +30,15 @@
 #include <errno.h>
 #include "epplet.h"
 
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#include <strings.h>
+#include <sys/resource.h>
+#include <devstat.h>
+#define BLKSIZ 512
+static struct statinfo si;
+#endif
+
 #if 0
 #  define D(x) do {printf("%10s | %7d:  [debug] ", __FILE__, __LINE__); printf x; fflush(stdout);} while (0)
 #else
@@ -73,12 +83,41 @@
 static void
 timer_cb(void *data)
 {
+   unsigned long       in_blks = 0, out_blks = 0;
+   static unsigned long last_in = 0, last_out = 0, in_delta = 0, out_delta = 0;
+   char                buff[1024];
+
+#ifdef __FreeBSD__
+   int ndevs;
+   int num_selected;
+   int num_selections;
+   int maxshowdevs = 10;
+   struct device_selection *dev_select = NULL;
+   struct devstat *dev;
+   long select_generation;
+   int dn, di;
+
+   if (devstat_getdevs(NULL, &si) == -1) return;
+   ndevs = si.dinfo->numdevs;
+
+   if (devstat_selectdevs(&dev_select, &num_selected, &num_selections,
+       &select_generation, si.dinfo->generation, si.dinfo->devices,
+       ndevs, NULL, 0, NULL, 0, DS_SELECT_ONLY, maxshowdevs, 1) == -1
+      ) return;
+
+   for (dn = 0; dn < ndevs; ++dn)
+   {
+       di = dev_select[dn].position;
+       dev = &si.dinfo->devices[di];
+       in_blks += dev->bytes[DEVSTAT_READ] / BLKSIZ;
+       out_blks += dev->bytes[DEVSTAT_WRITE] / BLKSIZ;
+   }
+
+   free(dev_select);
+#else
 
    FILE               *fp;
-   char                buff[1024];
    unsigned long       a, b, c, d, e;
-   unsigned long       in_blks = 0, out_blks = 0;
-   static unsigned long last_in = 0, last_out = 0, in_delta = 0, out_delta = 0;
 
    if ((fp = fopen("/proc/diskstats", "r")) == NULL)
      {
@@ -131,9 +170,11 @@
 	       }
 	  }
      }
+   fclose(fp);
+
+#endif
    in_blks -= last_in;
    out_blks -= last_out;
-   fclose(fp);
 
    if (last_in)
      {
@@ -273,6 +314,12 @@
 
    int                 prio;
 
+#ifdef __FreeBSD__
+   bzero(&si, sizeof(si));
+   si.dinfo = (struct devinfo *)malloc(sizeof(struct devinfo));
+   bzero(si.dinfo, sizeof(struct devinfo));
+#endif
+
    prio = getpriority(PRIO_PROCESS, getpid());
    setpriority(PRIO_PROCESS, getpid(), prio + 10);
    atexit(Epplet_cleanup);
