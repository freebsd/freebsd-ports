--- src/js/js.h.orig	Mon Sep  2 15:05:43 2002
+++ src/js/js.h	Thu Nov 28 21:43:15 2002
@@ -63,7 +63,7 @@
 #  include <fcntl.h>
 
 #  if defined(__FreeBSD__) || defined(__NetBSD__)
-#    include <machine/joystick.h>
+#    include <sys/joystick.h>
 #    define JS_DATA_TYPE joystick
 #    define JS_RETURN (sizeof(struct JS_DATA_TYPE))
 #  elif defined(__linux__)
@@ -132,9 +132,9 @@
 
 
 
-/*#if defined(__FreeBSD__) || defined(__NetBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
   int          id ;
-#endif*/
+#endif
 #ifdef WIN32
   JOYINFOEX    js       ;
   UINT         js_id    ;
