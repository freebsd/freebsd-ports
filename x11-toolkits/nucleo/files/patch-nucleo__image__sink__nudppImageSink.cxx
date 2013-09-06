--- ./nucleo/image/sink/nudppImageSink.cxx.orig	2008-07-21 13:47:54.000000000 +0200
+++ ./nucleo/image/sink/nudppImageSink.cxx	2013-09-06 23:12:11.854095550 +0200
@@ -18,6 +18,9 @@
 #include <unistd.h>
 #include <sys/socket.h>
 #include <sys/uio.h>
+#if defined(__FreeBSD__) && __FreeBSD_version < 701104
+#  include <netinet/in_systm.h>
+#endif
 #include <netinet/ip.h>
 
 #include <stdexcept>
