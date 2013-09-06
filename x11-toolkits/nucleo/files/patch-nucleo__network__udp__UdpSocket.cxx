--- ./nucleo/network/udp/UdpSocket.cxx.orig	2009-06-11 10:48:06.000000000 +0200
+++ ./nucleo/network/udp/UdpSocket.cxx	2013-09-06 23:14:02.591758270 +0200
@@ -16,6 +16,7 @@
 #include <sys/socket.h>
 #include <netdb.h>
 #include <sys/errno.h>
+#include <unistd.h>
 
 #include <stdexcept>
 #include <iostream>
