--- nucleo/network/dnssd/DNSServiceBrowser.H.orig	Thu May 24 15:41:15 2007
+++ nucleo/network/dnssd/DNSServiceBrowser.H	Thu May 24 15:41:38 2007
@@ -21,6 +21,7 @@
 #if NUCLEO_SUPPORTS_DNS_SD
 #include <arpa/inet.h>
 #include <dns_sd.h>
+#include <sys/socket.h>
 #include <net/if.h>
 #endif
 
