--- multiload/linux-proc.c.orig	Thu Jul 10 04:26:58 2003
+++ multiload/linux-proc.c	Mon Nov 17 23:54:38 2003
@@ -5,12 +5,17 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <assert.h>
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#include <net/if.h>
+#endif
 
 #include <glibtop.h>
 #include <glibtop/cpu.h>
 #include <glibtop/mem.h>
 #include <glibtop/swap.h>
 #include <glibtop/loadavg.h>
+#include <glibtop/netload.h>
 
 #include "linux-proc.h"
 
@@ -33,6 +38,10 @@
 static unsigned needed_loadavg_flags =
 (1 << GLIBTOP_LOADAVG_LOADAVG);
 
+static unsigned needed_netload_flags =
+(1 << GLIBTOP_NETLOAD_IF_FLAGS) +
+(1 << GLIBTOP_NETLOAD_BYTES_TOTAL);
+
 void
 GetLoad (int Maximum, int data [4], LoadGraph *g)
 {
@@ -236,6 +245,44 @@
     int delta[COUNT_TYPES], i;
     static int ticks = 0;
     static gulong past[COUNT_TYPES] = {0};
+#ifdef __FreeBSD__
+    struct if_nameindex *ifindex, *ifptr;
+    static int max = 500;
+
+    ifindex = if_nameindex();
+    if (!ifindex)
+        return;
+
+    memset(present, 0, sizeof (present));
+
+    for (ifptr = ifindex; ifptr->if_index && ifptr->if_name; ifptr++)
+    {
+        int index;
+        glibtop_netload netload; 
+
+        glibtop_get_netload(&netload, ifptr->if_name);
+        if (!netload.flags)
+            continue;
+
+        assert ((netload.flags & needed_netload_flags) == needed_netload_flags);
+
+        if (!(netload.if_flags & (1L << GLIBTOP_IF_FLAGS_UP)))
+            continue;
+        if (netload.if_flags & (1L << GLIBTOP_IF_FLAGS_LOOPBACK))
+            continue;
+
+        if (netload.if_flags & (1L << GLIBTOP_IF_FLAGS_POINTOPOINT)) {
+            index = strncmp(ifptr->if_name, "sl", 2) ? PPP_COUNT : SLIP_COUNT;
+        } else {
+            index = ETH_COUNT;
+        }
+
+        present[index] += netload.bytes_total;
+    }
+
+    if_freenameindex(ifindex);    
+
+#else
     static char *netdevfmt = NULL;
     char *cp, buffer[256];
     FILE *fp;
@@ -317,6 +364,7 @@
     }
 
     fclose(fp);
+#endif
 
     for (i = 0; i < 5; i++)
 	    data[i] = 0;
