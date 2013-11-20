--- daemon/gdm-xdmcp-display-factory.c.orig	2011-02-18 04:27:53.000000000 +0100
+++ daemon/gdm-xdmcp-display-factory.c	2011-03-11 13:14:10.000000000 +0100
@@ -35,6 +35,7 @@
 #include <netdb.h>
 #include <arpa/inet.h>
 #include <net/if.h>
+#include <netinet/in.h>
 #ifdef HAVE_SYS_SOCKIO_H
 #include <sys/sockio.h>
 #endif
@@ -76,7 +77,7 @@ int deny_severity = LOG_WARNING;
 #define DEFAULT_USE_MULTICAST         FALSE
 #define DEFAULT_MULTICAST_ADDRESS     "ff02::1"
 #define DEFAULT_HONOR_INDIRECT        TRUE
-#define DEFAULT_MAX_DISPLAYS_PER_HOST 1
+#define DEFAULT_MAX_DISPLAYS_PER_HOST 2
 #define DEFAULT_MAX_DISPLAYS          16
 #define DEFAULT_MAX_PENDING_DISPLAYS  4
 #define DEFAULT_MAX_WAIT              30
