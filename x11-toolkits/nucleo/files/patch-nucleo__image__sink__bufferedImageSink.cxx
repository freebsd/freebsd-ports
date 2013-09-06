--- ./nucleo/image/sink/bufferedImageSink.cxx.orig	2008-06-05 14:52:33.000000000 +0200
+++ ./nucleo/image/sink/bufferedImageSink.cxx	2013-09-06 23:16:07.949467532 +0200
@@ -10,6 +10,7 @@
  */
 
 #include <nucleo/image/sink/bufferedImageSink.H>
+#include <unistd.h>
 
 #define DEBUG_LEVEL 1
 
