--- ./nucleo/helpers/Phone.cxx.orig	2009-06-11 10:48:06.000000000 +0200
+++ ./nucleo/helpers/Phone.cxx	2013-09-06 23:16:41.291467318 +0200
@@ -18,6 +18,7 @@
 #include <fcntl.h>
 #include <sys/ioctl.h>
 #include <errno.h>
+#include <unistd.h>
 
 #include <iostream>
 #include <sstream>
