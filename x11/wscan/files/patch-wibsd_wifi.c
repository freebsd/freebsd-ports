--- wibsd_wifi.c.orig	Mon Dec 10 13:06:21 2001
+++ wibsd_wifi.c	Wed Mar 27 03:46:12 2002
@@ -49,7 +49,13 @@
 #include <net/ethernet.h>
 
 #define WICACHE
+
+#include <osreldate.h>
+#if __FreeBSD_version >= 500015
+#include <dev/wi/if_wavelan_ieee.h>
+#else
 #include <machine/if_wavelan_ieee.h>
+#endif
 
 #include <stdio.h>
 #include <string.h>
