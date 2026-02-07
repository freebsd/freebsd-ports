--- src/net/netSocket.h.orig	2008-03-11 05:06:20.000000000 +0300
+++ src/net/netSocket.h	2010-03-09 18:16:55.000000000 +0300
@@ -41,6 +41,8 @@
 #define NET_SOCKET_H
 
 #include "ul.h"
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <errno.h>
 
 /*
@@ -49,10 +51,11 @@
 class netAddress
 {
   /* DANGER!!!  This MUST match 'struct sockaddr_in' exactly! */
-  short          sin_family     ;
-  unsigned short sin_port       ;
-  unsigned int   sin_addr       ;
-  char           sin_zero [ 8 ] ;
+  int8_t            sin_len;
+  sa_family_t       sin_family;
+  in_port_t         sin_port;
+  in_addr_t         sin_addr;
+  char              sin_zero[8];
 
 public:
   netAddress () {}
