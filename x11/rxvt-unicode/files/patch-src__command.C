--- src/command.C.orig	2021-05-13 19:40:55 UTC
+++ src/command.C
@@ -57,6 +57,7 @@
 #endif
 
 #include <signal.h>
+#include <sys/param.h>
 
 #if LINUX_YIELD_HACK
 # include <time.h>
@@ -2368,7 +2369,9 @@ rxvt_term::next_char () noexcept
       if (len == (size_t)-2)
         {
           // the mbstate stores incomplete sequences. didn't know this :/
+#if __FreeBSD_version>502110
           cmdbuf_ptr = cmdbuf_endp;
+#endif
           break;
         }
 
