Fix ambiguous call on armv6.

--- kwin/effects/blur/blur.cpp.orig	2017-01-11 16:01:39 UTC
+++ kwin/effects/blur/blur.cpp
@@ -387,7 +387,7 @@ bool BlurEffect::shouldBlur(const Effect
     if (w->isDesktop())
         return false;
 
-    bool scaled = !qFuzzyCompare(data.xScale(), 1.0) && !qFuzzyCompare(data.yScale(), 1.0);
+    bool scaled = !qFuzzyCompare(data.xScale(), qreal(1.0)) && !qFuzzyCompare(data.yScale(), qreal(1.0));
     bool translated = data.xTranslation() || data.yTranslation();
 
     if (scaled || ((translated || (mask & PAINT_WINDOW_TRANSFORMED)) && !w->data(WindowForceBlurRole).toBool()))
