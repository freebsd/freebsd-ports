$FreeBSD$

--- painter.cpp.orig	Sat Mar 23 03:23:17 2002
+++ painter.cpp	Tue May 27 19:25:40 2003
@@ -9,6 +9,7 @@
 #include <cassert>
 #include <algorithm>
 #include <cmath>
+#include <iostream>
 
 #define DEF_FONT "fixed"
 #define DEF_ACTIVE_FG   "white"
@@ -420,7 +421,7 @@
 	cs = look->activeButtonFacet()->color();
     else
 	cs = look->inactiveButtonFacet()->color();
-    if ( std::fmod(width,2) == 0 )
+    if ( std::fmod((float)width,2) == 0 )
 	width--;
     height = width;
     int half = height/2;
@@ -428,13 +429,13 @@
     y += half - int(.2*height); // move down a bit
     height = half;              // reduce height
     setForeground( cs.color.pixel() );
-    drawLine( d, x, y, x + std::ceil(width/2) + 1, y + height + 1 );
-    drawLine( d, x + 1, y, x + std::ceil(width/2) + 1, y + height );
-    drawLine( d, x, y + 1,  x + std::ceil(width/2), y + height + 1 );
-    drawLine( d, x + std::ceil(width/2), y + height, x + width, y -1  );
-    drawLine( d, x + std::ceil(width/2), y + height-1, x +width-1, y-1 );
-    drawLine( d, x + std::ceil(width/2)+1, y + height, x +width, y );
-    drawPoint( d, x + std::ceil(width/2), y + height + 1 );
+    drawLine( d, x, y, x + (int) std::ceil((float)width/2) + 1, y + height + 1 );
+    drawLine( d, x + 1, y, x + (int) std::ceil((float)width/2) + 1, y + height );
+    drawLine( d, x, y + 1,  x + (int) std::ceil((float)width/2), y + height + 1 );
+    drawLine( d, x + (int) std::ceil((float)width/2), y + height, x + width, y -1  );
+    drawLine( d, x + (int) std::ceil((float)width/2), y + height-1, x +width-1, y-1 );
+    drawLine( d, x + (int) std::ceil((float)width/2)+1, y + height, x +width, y );
+    drawPoint( d, x + (int) std::ceil((float)width/2), y + height + 1 );
 }
 
 void Painter::setButtonBackground( Drawable d, Painter::Button b, bool active, 
