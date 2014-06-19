--- src/main.cc.orig	2003-06-23 22:55:04.000000000 +0200
+++ src/main.cc	2014-06-13 19:00:33.000000000 +0200
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
@@ -131,7 +133,7 @@
 		return -1;
 	    }
 	    else if (opt[0] == 'V') {
-		extern char *argp_program_version;
+		extern const char *argp_program_version;
 		cerr << argp_program_version << endl;
 		return -1;
 	    }
@@ -154,7 +156,7 @@
 		return -1;
 	    }
 	    else if (strcmp(opt, "version") == 0) {
-		extern char *argp_program_version;
+		extern const char *argp_program_version;
 		cerr << argp_program_version << endl;
 		return -1;
 	    }
@@ -187,7 +189,7 @@
 #define OPT_FPS 2
 #define OPT_FASTFORWARD 3
 
-char *mode_help =
+const char *mode_help =
 "\n"
 "Per-swarm modes and their default probabilities:\n"
 "  1: normal                                         p=20\n"
