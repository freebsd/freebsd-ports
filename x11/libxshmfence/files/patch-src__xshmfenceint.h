--- src/xshmfenceint.h	2013-11-20 17:14:05.000000000 -0500
+++ src/xshmfenceint.h	2013-12-09 15:14:36.000000000 -0500
@@ -23,6 +23,7 @@
 #ifndef _XSHMFENCEINT_H_
 #define _XSHMFENCEINT_H_
 
+#include <fcntl.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <sys/mman.h>
