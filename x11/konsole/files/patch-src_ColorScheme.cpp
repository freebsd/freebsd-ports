Fix ambiguous call on armv6.

--- src/ColorScheme.cpp.orig	2017-01-12 05:40:22 UTC
+++ src/ColorScheme.cpp
@@ -406,7 +406,7 @@ bool ColorSchemeWallpaper::draw(QPainter
     if (!_picture || _picture->isNull())
         return false;
 
-    if (qFuzzyCompare(1.0, opacity)) {
+    if (qFuzzyCompare(qreal(1.0), opacity)) {
         painter.drawTiledPixmap(rect, *_picture, rect.topLeft());
         return true;
     }
