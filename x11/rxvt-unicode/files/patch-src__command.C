--- src/command.C.orig	2012-01-19 14:34:39.000000000 +0100
+++ src/command.C	2012-01-23 19:28:46.000000000 +0100
@@ -57,6 +57,7 @@
 #endif
 
 #include <signal.h>
+#include <sys/param.h>
 
 #if LINUX_YIELD_HACK
 # include <time.h>
@@ -2354,7 +2355,9 @@
       if (len == (size_t)-2)
         {
           // the mbstate stores incomplete sequences. didn't know this :/
+#if __FreeBSD_version>502110
           cmdbuf_ptr = cmdbuf_endp;
+#endif
           break;
         }
 
