--- pango/pango-ot.h.orig	Tue Mar 16 16:21:00 2004
+++ pango/pango-ot.h	Tue Mar 16 16:21:18 2004
@@ -22,7 +22,8 @@
 #ifndef __PANGO_OT_H__
 #define __PANGO_OT_H__
 
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #include <pango/pango-glyph.h>
 
 G_BEGIN_DECLS
