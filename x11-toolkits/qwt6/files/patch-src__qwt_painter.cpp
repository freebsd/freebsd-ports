--- ./src/qwt_painter.cpp.orig	Mon Feb 26 23:22:13 2007
+++ ./src/qwt_painter.cpp	Fri Jun  8 22:22:59 2007
@@ -421,7 +421,7 @@
 
     painter->save();
 
-    painter->translate(scaledRect.x(), scaledRect.y());
+    painter->translate(scaledRect.x(), y);
     layout->draw(painter, context);
 
     painter->restore();
