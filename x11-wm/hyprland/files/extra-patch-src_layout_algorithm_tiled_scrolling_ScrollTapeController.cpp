--- src/layout/algorithm/tiled/scrolling/ScrollTapeController.cpp.orig	2026-03-07 12:05:56 UTC
+++ src/layout/algorithm/tiled/scrolling/ScrollTapeController.cpp
@@ -61,7 +61,7 @@ void CScrollTapeController::insertStrip(ssize_t afterI
         return;
     }
 
-    afterIndex = std::clamp(afterIndex, -1L, sc<ssize_t>(INT32_MAX));
+    afterIndex = std::clamp(afterIndex, sc<ssize_t>(-1), sc<ssize_t>(INT32_MAX));
 
     SStripData newStrip;
     newStrip.size = size;
