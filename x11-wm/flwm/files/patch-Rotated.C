--- Rotated.C.orig	2008-12-07 22:19:57.000000000 +0100
+++ Rotated.C	2008-12-07 22:20:12.000000000 +0100
@@ -368,9 +368,11 @@
 }
 
 void draw_rotated(const char* text, int n, int x, int y, int angle) {
+#if 0
   if (!text || !*text) return;
   setrotfont(angle);
   XRotDrawString(fl_display, font, fl_window, fl_gc, x, y, text, n);
+#endif
 }
 
 #if !defined(FLWM) || FL_MAJOR_VERSION>=2
