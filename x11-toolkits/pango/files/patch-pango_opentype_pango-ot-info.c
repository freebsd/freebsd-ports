--- pango/opentype/pango-ot-info.c.orig	Tue Mar 16 16:18:19 2004
+++ pango/opentype/pango-ot-info.c	Tue Mar 16 16:17:38 2004
@@ -22,7 +22,7 @@
 #include "pango-ot-private.h"
 #include "fterrcompat.h"
 #include <freetype/internal/ftobjs.h>
-#include <freetype/ftmodule.h>
+#include <freetype/ftmodapi.h>
 
 static void pango_ot_info_class_init (GObjectClass *object_class);
 static void pango_ot_info_finalize   (GObject *object);
