--- ./nucleo/image/sink/nserverImageSink.H.orig	2008-06-05 14:52:33.000000000 +0200
+++ ./nucleo/image/sink/nserverImageSink.H	2013-09-06 23:18:00.405460374 +0200
@@ -24,6 +24,7 @@
 #include <stdexcept>
 
 #include <sys/socket.h>
+#include <unistd.h>
 
 namespace nucleo {
 
