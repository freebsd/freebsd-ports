--- Xtransint.h.orig	2013-11-08 10:46:59.086340096 +0100
+++ Xtransint.h	2013-11-08 11:02:02.275278727 +0100
@@ -72,7 +72,7 @@
 #  define XTRANSDEBUG 1
 #endif
 
-#if XTRANS_SEND_FDS && !(defined(linux) || defined(__sun))
+#if XTRANS_SEND_FDS && !(defined(linux) || defined(__sun) || defined(__FreeBSD__))
 #error "FD passing support only on Linux & Solaris"
 #endif
 
