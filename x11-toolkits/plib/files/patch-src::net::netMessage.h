--- src/net/netMessage.h.orig	Sat Mar 16 01:23:39 2002
+++ src/net/netMessage.h	Sat Mar 16 01:24:23 2002
@@ -46,6 +46,8 @@
 #include <netinet/in.h> // ntohs() etc prototypes
 #endif
 
+#include <arpa/inet.h>
+
 
 class netGuid //Globally Unique IDentifier
 {
