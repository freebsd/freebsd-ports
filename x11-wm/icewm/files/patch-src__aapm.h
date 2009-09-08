--- ./src/aapm.h.orig	2009-01-25 09:39:51.000000000 -0500
+++ ./src/aapm.h	2009-09-03 16:12:50.000000000 -0400
@@ -1,5 +1,5 @@
 
-#if defined(linux) || (defined (__FreeBSD__) && defined(i386)) || (defined(__NetBSD__) && defined(i386))
+#if defined(linux) || (defined (__FreeBSD__)) || (defined(__NetBSD__) && defined(i386))
 
 #include "ywindow.h"
 #include "ytimer.h"
