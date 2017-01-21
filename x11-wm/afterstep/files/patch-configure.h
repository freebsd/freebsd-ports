--- configure.h.orig	1997-03-02 19:50:40 UTC
+++ configure.h
@@ -1,6 +1,6 @@
-#define AFTERDIR     "/usr/lib/X11/afterstep"
-#define AFTER_ICONDIR   "/usr/include/X11/bitmaps:/usr/include/X11/pixmaps"
-#define STEPRC         "/usr/lib/X11/afterstep/system.steprc"
+#define AFTERDIR     "%%PREFIX%%/lib/X11/afterstep"
+#define AFTER_ICONDIR   "%%PREFIX%%/include/X11/bitmaps:%%PREFIX%%/include/X11/pixmaps"
+#define STEPRC         "%%PREFIX%%/lib/X11/afterstep/system.steprc"
 
 /* If you would like gradients, uncomment this */
 #define ENABLE_TEXTURE
@@ -17,7 +17,7 @@
  * Imake wants to leave binaries, then choose the second line here.
  * If you want to install it in a different directory, uncomment and
  * edit the first line */
-#define AFTER_BIN_DIR BINDIR=/usr/bin/X11
+#define AFTER_BIN_DIR BINDIR=%%PREFIX%%/bin
 
 /* Compiler over-ride for Imakefiles */
 /* Leave it as shown to get your default compiler */
@@ -59,7 +59,7 @@
  ***************************************************************************/
 #define XPM                      
 /*  linker flags needed to locate and link in the Xpm library, if you use it */
-#define XPMLIBRARY -L/usr/lib/X11 -lXpm
+#define XPMLIBRARY -L%%LOCALBASE%%/lib -lXpm
 
 /***************************************************************************
  *#define M4
