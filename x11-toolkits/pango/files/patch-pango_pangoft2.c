--- pango/pangoft2.c.orig	Tue Mar 16 16:21:59 2004
+++ pango/pangoft2.c	Tue Mar 16 16:22:20 2004
@@ -28,7 +28,8 @@
 #include <glib.h>
 #include <glib/gprintf.h>
 
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 
 #include "pango-utils.h"
 #include "pangoft2.h"
