--- common/gdm-address.c.orig	2008-04-17 23:29:27.000000000 -0400
+++ common/gdm-address.c	2008-05-02 14:36:15.000000000 -0400
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
 
