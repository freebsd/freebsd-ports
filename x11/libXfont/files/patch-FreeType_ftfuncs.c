--- FreeType/ftfuncs.c.orig	Sun Mar 21 18:29:28 2004
+++ FreeType/ftfuncs.c	Sun Mar 21 18:29:46 2004
@@ -31,7 +31,8 @@
 #include "fntfilst.h"
 #include "fontutil.h"
 #include <X11/fonts/FSproto.h>
-#include "freetype/freetype.h"
+#include "ft2build.h"
+#include FT_FREETYPE_H
 #include "freetype/ftsizes.h"
 #include "freetype/ttnameid.h"
 #include "freetype/tttables.h"
