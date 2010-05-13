--- nucleo/image/sink/nudppImageSink.cxx.orig	2010-05-14 03:50:14.379819227 +0700
+++ nucleo/image/sink/nudppImageSink.cxx	2010-05-14 03:55:16.360199694 +0700
@@ -18,6 +18,9 @@
 #include <unistd.h>
 #include <sys/socket.h>
 #include <sys/uio.h>
+#if defined(__FreeBSD__) && __FreeBSD_version < 701104
+#  include <netinet/in_systm.h>
+#endif
 #include <netinet/ip.h>
 
 #include <stdexcept>
