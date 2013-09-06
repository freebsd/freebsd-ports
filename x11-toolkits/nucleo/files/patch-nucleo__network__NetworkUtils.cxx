--- ./nucleo/network/NetworkUtils.cxx.orig	2008-06-05 14:52:33.000000000 +0200
+++ ./nucleo/network/NetworkUtils.cxx	2013-09-06 23:14:48.950072240 +0200
@@ -15,6 +15,7 @@
 
 #include <arpa/inet.h>
 #include <netdb.h>
+#include <unistd.h>
 
 #include <iostream>
 #include <string>
