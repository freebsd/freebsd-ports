--- src/net/netSocket.cxx.orig	Sun Oct 14 21:13:16 2001
+++ src/net/netSocket.cxx	Sun Oct 14 21:13:48 2001
@@ -46,6 +46,7 @@
 
 /* Paul Wiltsey says we need this for Solaris 2.8 */
  
+#include <netinet/in.h>
 #ifndef INADDR_NONE
 #define INADDR_NONE ((unsigned long)-1)
 #endif
