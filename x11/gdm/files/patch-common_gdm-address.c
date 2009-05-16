--- common/gdm-address.c.orig	2009-02-19 21:45:13.000000000 -0500
+++ common/gdm-address.c	2009-05-11 02:38:17.000000000 -0400
@@ -29,6 +29,8 @@
 #include <stropts.h>
 #endif
 #include <string.h>
+#include <sys/types.h>
+#include <sys/param.h>
 #ifdef HAVE_SYS_SOCKET_H
 #include <sys/socket.h>
 #endif
@@ -37,7 +39,6 @@
 #endif
 #include <netdb.h>
 #include <sys/ioctl.h>
-#include <net/if.h>
 
 #ifndef G_OS_WIN32
 #include <sys/select.h>
@@ -47,6 +48,7 @@
 #include <winsock2.h>
 #include <ws2tcpip.h>
 #endif
+#include <net/if.h>
 
 #include <glib-object.h>
 
@@ -206,7 +208,7 @@ gdm_address_get_hostname (GdmAddress *ad
 
         host [0] = '\0';
         res = getnameinfo ((const struct sockaddr *)address->ss,
-                           sizeof (struct sockaddr_storage),
+                           gdm_sockaddr_len (address->ss),
                            host, sizeof (host),
                            NULL, 0,
                            0);
@@ -245,7 +247,7 @@ gdm_address_get_numeric_info (GdmAddress
         host [0] = '\0';
         serv [0] = '\0';
         res = getnameinfo ((const struct sockaddr *)address->ss,
-                           sizeof (struct sockaddr_storage),
+                           gdm_sockaddr_len (address->ss),
                            host, sizeof (host),
                            serv, sizeof (serv),
                            NI_NUMERICHOST | NI_NUMERICSERV);
