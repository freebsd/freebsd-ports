--- src/command.C.orig	Wed Dec 15 06:38:28 2004
+++ src/command.C	Thu Dec 16 20:33:55 2004
@@ -51,6 +51,8 @@
 #include "command.h"
 
 #include <wchar.h>
+#include <sys/param.h>
+#include <sys/types.h>
 #include <signal.h>
 
 /*----------------------------------------------------------------------*/
@@ -2700,7 +2702,9 @@
       if (len == (size_t)-2)
         {
           // the mbstate stores incomplete sequences. didn't know this :/
+#if __FreeBSD_version>502110
           cmdbuf_ptr = cmdbuf_endp;
+#endif
           break;
         }
 
