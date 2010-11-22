--- ./plugins/chart/chart.c.orig	2010-05-02 02:13:47.000000000 -0700
+++ ./plugins/chart/chart.c	2010-11-17 11:06:07.000000000 -0800
@@ -24,7 +24,13 @@
 #include <string.h>
 #include <sys/time.h>
 #include <time.h>
+#ifdef __FreeBSD__
+# include <sys/types.h>
+# include <sys/resource.h>
+# include <sys/sysctl.h>
+#else
 #include <sys/sysinfo.h>
+#endif
 #include <stdlib.h>
 
 #include "plugin.h"
