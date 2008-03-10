--- epplets/net.c.orig	2006-04-16 00:32:43.000000000 +0200
+++ epplets/net.c	2008-03-10 21:26:47.000000000 +0100
@@ -1,5 +1,6 @@
 /*
  * Copyright (C) 1999-2000, Michael Jennings
+ * 		 2008, Pietro Cerutti <gahr@FreeBSD.org> (FreeBSD adaptation)
  *
  * Permission is hereby granted, free of charge, to any person obtaining a copy
  * of this software and associated documentation files (the "Software"), to
@@ -38,6 +39,14 @@
 #ifdef linux
 # include <linux/version.h>
 #endif
+#ifdef __FreeBSD__
+# include <sys/types.h>
+# include <sys/socket.h>
+# include <sys/sysctl.h>
+# include <sys/time.h>
+# include <net/if.h>
+# include <net/if_mib.h>
+#endif
 #include "epplet.h"
 #include "net.h"
 
@@ -86,6 +95,48 @@
      }
    fclose(fp);
    return (names);
+
+#elif defined(__FreeBSD__)
+
+   struct ifmibdata data;
+   int ifno_mib[5];
+   int fmib_mib[6];
+   int nof_rows, idx, row;
+   size_t len;
+
+   ifno_mib[0] = CTL_NET;
+   ifno_mib[1] = PF_LINK;
+   ifno_mib[2] = NETLINK_GENERIC;
+   ifno_mib[3] = IFMIB_SYSTEM;
+   ifno_mib[4] = IFMIB_IFCOUNT;
+
+   fmib_mib[0] = CTL_NET;
+   fmib_mib[1] = PF_LINK;
+   fmib_mib[2] = NETLINK_GENERIC;
+   fmib_mib[3] = IFMIB_IFDATA;
+   fmib_mib[5] = IFDATA_GENERAL;
+
+   len = sizeof(nof_rows);
+
+   sysctl(ifno_mib, 5, &nof_rows, &len, NULL, 0);
+
+   len = sizeof(data);
+
+   for(row=1, idx=0; row <= nof_rows; row++) {
+      fmib_mib[4] = row;
+      if(sysctl(fmib_mib, 6, &data, &len, NULL, 0) && errno == ENOENT)
+         continue;
+      else  {
+         names = realloc(names, sizeof(char *) * ++idx);
+         names[idx-1] = strdup(data.ifmd_name);
+      }
+   }
+   names[idx] = NULL;
+
+   if(count) *count = idx;
+   return (names);
+
+
 #elif defined(__sun__)
    return ((char **)NULL);
 #else
@@ -107,8 +158,11 @@
    FILE               *fp;
    char                buff[256], *colon =
       NULL, dev[64], in_str[64], out_str[64];
+#elif defined(__FreeBSD__)
+   struct ifmibdata data;
+   int mib[6], ifno_mib[5], row, nof_ifaces;
+   size_t len;
 #endif
-
    if (device == NULL)
      {
 	return (EFAULT);
@@ -173,6 +227,43 @@
      }
    fclose(fp);
    return ((match) ? (0) : (ENODEV));
+#elif defined(__FreeBSD__)
+   ifno_mib[0] = CTL_NET;
+   ifno_mib[1] = PF_LINK;
+   ifno_mib[2] = NETLINK_GENERIC;
+   ifno_mib[3] = IFMIB_SYSTEM;
+   ifno_mib[4] = IFMIB_IFCOUNT;
+
+   len = sizeof(nof_ifaces);
+
+   sysctl(ifno_mib, 5, &nof_ifaces, &len, NULL, 0);
+
+   mib[0] = CTL_NET;
+   mib[1] = PF_LINK;
+   mib[2] = NETLINK_GENERIC;
+   mib[3] = IFMIB_IFDATA;
+   mib[5] = IFDATA_GENERAL;
+   
+   len = sizeof(data);
+
+   for(row=1; row<=nof_ifaces; row++) {
+      mib[4] = row;
+
+      if(sysctl(mib, 6, &data, &len, NULL, 0) && errno == ENOENT)
+         continue;
+
+      if(strcmp(device, data.ifmd_name))
+         continue;
+
+      if(in_bytes)
+         *in_bytes = (double)data.ifmd_data.ifi_ibytes;
+      if(out_bytes)
+         *out_bytes = (double)data.ifmd_data.ifi_obytes;
+      return (0);
+   }
+
+   return (ENODEV);
+
 #else
    /* Unsupported platform. */
    if (in_bytes != NULL)
