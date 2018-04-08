Avoid selecting BGR visuals. On Intel i915 systems, selecting one of
these results in red-blue swapping later in the graphics pipeline.
PR 223638 has an extensive discussion.

--- src/platformsupport/glxconvenience/qglxconvenience.cpp.orig	2018-01-16 06:53:43 UTC
+++ src/platformsupport/glxconvenience/qglxconvenience.cpp
@@ -220,6 +220,10 @@ GLXFBConfig qglx_findConfig(Display *dis
             if (requestedAlpha && actualAlpha != requestedAlpha)
                 continue;
 
+            // avoid BGR visuals due to bugs elsewhere
+            if ((visual->red_mask & 0x1) == 0x1)
+                continue;
+
             return candidate;
         }
     } while (qglx_reduceFormat(&format));
