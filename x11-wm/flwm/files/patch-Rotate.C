--- Rotated.C.orig	Fri Aug 27 21:53:28 2004
+++ Rotated.C	Fri Aug 27 12:02:59 2004
@@ -27,6 +27,7 @@
 /* ********************************************************************** */
 
 #include <FL/x.H>
+#include <X11/Xft/Xft.h>
 #include <FL/fl_draw.H>
 #include "Rotated.H"
 #include <stdlib.h>
@@ -352,6 +353,7 @@
 static XRotFontStruct* font;
 
 void draw_rotated(const char* text, int n, int x, int y, int angle) {
+#if XFT_MAJOR < 2
   if (!text || !*text) return;
   /* make angle positive ... */
   if (angle < 0) do angle += 360; while (angle < 0);
@@ -365,6 +367,7 @@
     font = XRotLoadFont(fl_display, fl_xfont, dir);
   }
   XRotDrawString(fl_display, font, fl_window, fl_gc, x, y, text, n);
+#endif
 }
 
 #ifndef FLWM
