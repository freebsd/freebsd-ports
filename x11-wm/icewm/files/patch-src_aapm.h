--- src/aapm.h.orig	Sat Sep 27 16:54:45 2003
+++ src/aapm.h	Sun Oct 19 09:17:31 2003
@@ -1,7 +1,5 @@
 
-#ifndef linux
-#undef CONFIG_APPLET_APM
-#elif CONFIG_APPLET_APM
+#if (defined(linux) || defined (__FreeBSD__)) && defined(i386)
 
 #include "ywindow.h"
 #include "ytimer.h"
@@ -64,4 +62,6 @@
     char *acpiACName;
 
 };
+#else
+#undef CONFIG_APPLET_APM
 #endif
