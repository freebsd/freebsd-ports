--- ./nucleo/image/sink/novImageSink.cxx.orig	2008-06-05 14:52:33.000000000 +0200
+++ ./nucleo/image/sink/novImageSink.cxx	2013-09-06 23:15:36.719237812 +0200
@@ -18,6 +18,7 @@
 #include <nucleo/image/encoding/Conversion.H>
 
 #include <sys/uio.h>
+#include <unistd.h>
 
 #include <stdexcept>
 
