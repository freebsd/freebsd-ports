--- programs/mkfontscale/mkfontscale.c.orig	Wed Mar 17 07:01:52 2004
+++ programs/mkfontscale/mkfontscale.c	Wed Mar 17 07:03:10 2004
@@ -29,7 +29,8 @@
 #include <dirent.h>
 
 #include <X11/fonts/fontenc.h>
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #include <freetype/ftsnames.h>
 #include <freetype/tttables.h>
 #include <freetype/ttnameid.h>
