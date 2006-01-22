--- src/fdpass.C.orig	Sun Jan 22 18:08:42 2006
+++ src/fdpass.C	Sun Jan 22 22:40:54 2006
@@ -28,6 +28,9 @@
 #include <sys/uio.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#if defined(__FreeBSD__)
+#include <stddef.h>
+#endif
 
 #include "libptytty.h"
 
