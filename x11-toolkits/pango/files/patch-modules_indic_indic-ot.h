--- modules/indic/indic-ot.h.orig	Tue Mar 16 16:23:13 2004
+++ modules/indic/indic-ot.h	Tue Mar 16 16:23:38 2004
@@ -9,7 +9,8 @@
 #ifndef __INDIC_OT_H__
 #define __INDIC_OT_H__
 
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #include <pango/pango-glyph.h>
 #include <pango/pango-types.h>
 #include "mprefixups.h"
