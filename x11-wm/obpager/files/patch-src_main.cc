--- src/main.cc.orig	2004-09-01 14:23:44 UTC
+++ src/main.cc
@@ -26,6 +26,7 @@
 
 #include <sys/types.h>
 #include <unistd.h>
+#include <errno.h>
 
 
 // Include the headers for the pager class and also the spiffy custom exception class
