--- src/net/netSocket.cxx.orig	2008-03-11 05:06:20.000000000 +0300
+++ src/net/netSocket.cxx	2010-03-09 18:53:58.000000000 +0300
@@ -38,6 +38,7 @@
 #include <unistd.h>
 #include <netdb.h>
 #include <fcntl.h>
+#include <stddef.h>
 
 #else
 
@@ -64,8 +65,10 @@
 
 void netAddress::set ( const char* host, int port )
 {
+  int dummy[(sizeof(netAddress) == sizeof(sockaddr_in))*2-1]; // Compile time assert
   memset(this, 0, sizeof(netAddress));
 
+  sin_len = sizeof(netAddress);
   sin_family = AF_INET ;
   sin_port = htons (port);
 
