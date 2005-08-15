--- src/command.C.orig	Tue Jul 12 22:11:42 2005
+++ src/command.C	Mon Aug 15 00:40:13 2005
@@ -55,6 +55,7 @@
 #endif
 
 #include <csignal>
+#include <sys/param.h>
 
 /*----------------------------------------------------------------------*/
 
@@ -2716,7 +2717,9 @@
       if (len == (size_t)-2)
         {
           // the mbstate stores incomplete sequences. didn't know this :/
+#if __FreeBSD_version>502110
           cmdbuf_ptr = cmdbuf_endp;
+#endif
           break;
         }
 
