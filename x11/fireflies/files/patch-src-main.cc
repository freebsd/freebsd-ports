--- src/main.cc.orig	Tue Jun 24 05:55:04 2003
+++ src/main.cc	Wed Feb 15 02:32:39 2006
@@ -15,8 +15,10 @@
 #ifdef WIN32
 #include <windows.h>
 #else
+#ifdef HAVE_ARGP_H
 #include <argp.h>
 #endif
+#endif
 
 CanvasBase *canvas;
 Scene scene;
@@ -26,7 +28,7 @@
 int mspf = 1000/30;
 bool full_screen = false;
 
-#ifdef WIN32
+#if defined(WIN32) || !defined (HAVE_ARGP_H)
 // mingw doesn't have argp. implement half-assed version
 
 #define OPTION_HIDDEN 1
