--- FreeType/fttools.c.orig	Sun Mar 21 18:30:36 2004
+++ FreeType/fttools.c	Sun Mar 21 18:30:56 2004
@@ -34,7 +34,8 @@
 #endif
 
 #include "font.h"
-#include "freetype/freetype.h"
+#include "ft2build.h"
+#include FT_FREETYPE_H
 #include "freetype/ftsnames.h"
 #include "freetype/ttnameid.h"
 #include "ft.h"
