--- src/xshmfenceint.h.orig	2015-03-04 15:38:56 UTC
+++ src/xshmfenceint.h
@@ -23,6 +23,7 @@
 #ifndef _XSHMFENCEINT_H_
 #define _XSHMFENCEINT_H_
 
+#include <fcntl.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <sys/mman.h>
