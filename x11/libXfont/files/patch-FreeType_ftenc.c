--- FreeType/ftenc.c.orig	Sun Mar 21 18:28:11 2004
+++ FreeType/ftenc.c	Sun Mar 21 18:28:50 2004
@@ -29,7 +29,8 @@
 
 #include "fontmisc.h"
 #include "fontenc.h"
-#include "freetype/freetype.h"
+#include "ft2build.h"
+#include FT_FREETYPE_H
 #include "freetype/ttnameid.h"
 #include "freetype/tttables.h"
 #include "freetype/t1tables.h"
