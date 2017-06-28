Fix ambiguous call on armv6.

--- kwin/scene_xrender.cpp.orig	2017-01-11 16:04:04 UTC
+++ kwin/scene_xrender.cpp
@@ -392,7 +392,7 @@ void SceneXrender::Window::performPaint(
 {
     setTransformedShape(QRegion());  // maybe nothing will be painted
     // check if there is something to paint
-    bool opaque = isOpaque() && qFuzzyCompare(data.opacity(), 1.0);
+    bool opaque = isOpaque() && qFuzzyCompare(data.opacity(), qreal(1.0));
     /* HACK: It seems this causes painting glitches, disable temporarily
     if (( mask & PAINT_WINDOW_OPAQUE ) ^ ( mask & PAINT_WINDOW_TRANSLUCENT ))
         { // We are only painting either opaque OR translucent windows, not both
@@ -469,7 +469,7 @@ void SceneXrender::Window::performPaint(
         xscale *= screen_paint.xScale();
         yscale *= screen_paint.yScale();
     }
-    if (!qFuzzyCompare(xscale, 1.0) || !qFuzzyCompare(yscale, 1.0)) {
+    if (!qFuzzyCompare(xscale, qreal(1.0)) || !qFuzzyCompare(yscale, qreal(1.0))) {
         scaled = true;
         xform.matrix11 = DOUBLE_TO_FIXED(1.0 / xscale);
         xform.matrix22 = DOUBLE_TO_FIXED(1.0 / yscale);
