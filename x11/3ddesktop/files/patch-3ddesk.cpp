--- 3ddesk.cpp.orig	Mon May 10 01:44:54 2004
+++ 3ddesk.cpp	Thu Aug 26 22:59:52 2004
@@ -22,6 +22,7 @@
 #include <stdlib.h>
 #include <errno.h>
 #include <sys/types.h>
+#include <sys/time.h>
 #include <sys/ipc.h>
 #include <sys/msg.h>
 #include <string.h>
