--- src/aapm.h.orig	Sun Aug 24 23:59:25 2003
+++ src/aapm.h	Wed Sep 10 04:57:40 2003
@@ -1,5 +1,5 @@
 
-#ifndef linux
+#if !defined(linux) && !defined(__FreeBSD__) && !defined(i386)
 #undef CONFIG_APPLET_APM
 #elif CONFIG_APPLET_APM
 
