--- src/main.cc.orig	2009-03-07 18:24:50.000000000 +0100
+++ src/main.cc	2009-03-07 18:24:58.000000000 +0100
@@ -26,6 +26,7 @@
 
 #include <sys/types.h>
 #include <unistd.h>
+#include <errno.h>
 
 
 // Include the headers for the pager class and also the spiffy custom exception class
