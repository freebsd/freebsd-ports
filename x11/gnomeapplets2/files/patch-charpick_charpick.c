--- charpick/charpick.c.orig	Wed Sep 10 13:33:00 2003
+++ charpick/charpick.c	Wed Sep 10 13:33:19 2003
@@ -3,7 +3,7 @@
  */
 
 #include <config.h>
-#ifndef sun
+#if !defined(sun) && !defined(__FreeBSD__)
   #include <tgmath.h>
 #endif
 #include <panel-applet.h>
