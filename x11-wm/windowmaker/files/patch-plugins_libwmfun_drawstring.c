--- plugins/libwmfun/drawstring.c	2001/01/09 16:22:05	1.1
+++ plugins/libwmfun/drawstring.c	2001/01/09 16:22:54
@@ -4,7 +4,7 @@
 #include "generic.h"
 
 #ifdef USE_FREETYPE
-#include <freetype/freetype.h>
+#include <freetype2/freetype/freetype.h>
 #endif
 
 #define MAX_GLYPHS 256
