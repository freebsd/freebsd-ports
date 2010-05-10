--- daemon/gdm-xdmcp-display-factory.c.orig	2009-12-21 17:36:30.000000000 +0100
+++ daemon/gdm-xdmcp-display-factory.c	2009-12-26 23:26:24.000000000 +0100
@@ -35,6 +35,7 @@
 #include <netdb.h>
 #include <arpa/inet.h>
 #include <net/if.h>
+#include <netinet/in.h>
 #ifdef HAVE_SYS_SOCKIO_H
 #include <sys/sockio.h>
 #endif
@@ -76,7 +77,7 @@
 #define DEFAULT_USE_MULTICAST         FALSE
 #define DEFAULT_MULTICAST_ADDRESS     "ff02::1"
 #define DEFAULT_HONOR_INDIRECT        TRUE
-#define DEFAULT_MAX_DISPLAYS_PER_HOST 1
+#define DEFAULT_MAX_DISPLAYS_PER_HOST 2
 #define DEFAULT_MAX_DISPLAYS          16
 #define DEFAULT_MAX_PENDING_DISPLAYS  4
 #define DEFAULT_MAX_WAIT              30
@@ -404,6 +405,11 @@
 create_socket (struct addrinfo *ai)
 {
         int sock;
+#ifdef ENABLE_IPV6
+#ifdef IPV6_V6ONLY
+	int off = 0;
+#endif
+#endif
 
         sock = socket (ai->ai_family, ai->ai_socktype, ai->ai_protocol);
         if (sock < 0) {
@@ -411,6 +417,16 @@
                 return sock;
         }
 
+#ifdef ENABLE_IPV6
+#ifdef IPV6_V6ONLY
+	if (setsockopt (sock, IPPROTO_IPV6, IPV6_V6ONLY, (void *)&off, sizeof (off)) < 0) {
+		g_warning ("setsockopt: %s", g_strerror (errno));
+		close (sock);
+		return -1;
+	}
+#endif
+#endif
+
         if (bind (sock, ai->ai_addr, ai->ai_addrlen) < 0) {
                 g_warning ("bind: %s", g_strerror (errno));
                 close (sock);
