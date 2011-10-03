--- src/command.C.orig	2011-06-22 14:44:37.000000000 +0400
+++ src/command.C	2011-09-21 15:39:21.000000000 +0400
@@ -57,6 +57,7 @@
 #endif
 
 #include <csignal>
+#include <sys/param.h>
 
 #if LINUX_YIELD_HACK
 # include <ctime>
@@ -2357,7 +2358,9 @@
       if (len == (size_t)-2)
         {
           // the mbstate stores incomplete sequences. didn't know this :/
+#if __FreeBSD_version>502110
           cmdbuf_ptr = cmdbuf_endp;
+#endif
           break;
         }
 
