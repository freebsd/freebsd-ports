--- ksysguard/ksysguardd/FreeBSD/netdev.c.orig	Fri Oct 11 18:06:41 2002
+++ ksysguard/ksysguardd/FreeBSD/netdev.c	Fri Oct 11 18:06:58 2002
@@ -20,6 +20,7 @@
 */
 
 #include <fcntl.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <net/if.h>
 #include <net/if_mib.h>
@@ -27,7 +28,6 @@
 #include <string.h>
 #include <sys/sysctl.h>
 #include <sys/time.h>
-#include <sys/types.h>
 #include <unistd.h>
 
 
