--- src/Screen.hh.orig	Wed May 12 15:55:06 2004
+++ src/Screen.hh	Wed Mar  2 19:58:43 2005
@@ -25,6 +25,8 @@
 extern "C" {
 #include <X11/Xlib.h>
 
+#include <cairo-xlib.h>
+
 #ifdef    XINERAMA
 #  include <X11/extensions/Xinerama.h>
 #endif // XINERAMA
