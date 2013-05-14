--- src/main.cc	2003-06-23 16:55:04.000000000 -0400
+++ src/main.cc	2013-05-13 14:24:28.000000000 -0400
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
@@ -187,7 +189,7 @@
 #define OPT_FPS 2
 #define OPT_FASTFORWARD 3
 
-char *mode_help =
+const char *mode_help =
 "\n"
 "Per-swarm modes and their default probabilities:\n"
 "  1: normal                                         p=20\n"
