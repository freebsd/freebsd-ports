--- src/js/js.h.orig	Mon Sep  2 15:05:43 2002
+++ src/js/js.h	Wed Sep  4 04:44:26 2002
@@ -132,9 +132,9 @@
 
 
 
-/*#if defined(__FreeBSD__) || defined(__NetBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
   int          id ;
-#endif*/
+#endif
 #ifdef WIN32
   JOYINFOEX    js       ;
   UINT         js_id    ;
