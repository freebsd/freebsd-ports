--- src/Render.hh.orig	Thu Nov  4 06:22:46 2004
+++ src/Render.hh	Thu Mar  3 18:19:13 2005
@@ -28,6 +28,8 @@
 #ifdef    SVG
 #include <svg-cairo.h>
 #endif // SVG  
+
+#include <X11/Xlib.h>
 }
 
 #include "RefCounted.hh"
