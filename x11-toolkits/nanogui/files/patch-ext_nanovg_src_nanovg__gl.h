--- ext/nanovg/src/nanovg_gl.h.orig	2025-09-06 22:13:27 UTC
+++ ext/nanovg/src/nanovg_gl.h
@@ -111,7 +111,7 @@ enum NVGimageFlagsGL {
 #include <stdio.h>
 #include <string.h>
 #include <math.h>
-#include "nanovg.h"
+#include <nanovg.h>
 
 enum GLNVGuniformLoc {
 	GLNVG_LOC_VIEWSIZE,
