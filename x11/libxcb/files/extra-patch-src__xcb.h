--- ./src/xcb.h.orig	Sat Oct  7 22:31:54 2006
+++ ./src/xcb.h	Sun Nov  5 12:22:13 2006
@@ -29,7 +29,7 @@
 #define __XCB_H__
 #include <sys/types.h>
 
-#if defined(__solaris__)
+#if defined(__solaris__) || __FreeBSD__ < 5
 #include <inttypes.h>
 #else
 #include <stdint.h>
