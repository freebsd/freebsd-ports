--- daemon/gdm-xdmcp-display-factory.c.orig	2007-11-01 10:15:58.269325570 -0400
+++ daemon/gdm-xdmcp-display-factory.c	2007-11-01 10:20:19.093220785 -0400
@@ -35,6 +35,7 @@
 #include <netdb.h>
 #include <arpa/inet.h>
 #include <net/if.h>
+#include <netinet/in.h>
 #ifdef HAVE_SYS_SOCKIO_H
 #include <sys/sockio.h>
 #endif
