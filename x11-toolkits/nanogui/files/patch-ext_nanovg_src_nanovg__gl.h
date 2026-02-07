--- ext/nanovg/src/nanovg_gl.h.orig	2021-10-16 18:18:49 UTC
+++ ext/nanovg/src/nanovg_gl.h
@@ -113,7 +113,7 @@ enum NVGimageFlagsGL {
 #include <stdio.h>
 #include <string.h>
 #include <math.h>
-#include "nanovg.h"
+#include <nanovg.h>
 
 enum GLNVGuniformLoc {
 	GLNVG_LOC_VIEWSIZE,
