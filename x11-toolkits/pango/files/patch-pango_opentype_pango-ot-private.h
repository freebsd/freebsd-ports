--- pango/opentype/pango-ot-private.h.orig	Tue Mar 16 16:16:35 2004
+++ pango/opentype/pango-ot-private.h	Tue Mar 16 16:18:53 2004
@@ -22,7 +22,8 @@
 #ifndef __PANGO_OT_PRIVATE_H__
 #define __PANGO_OT_PRIVATE_H__
 
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 
 #include <glib-object.h>
 
