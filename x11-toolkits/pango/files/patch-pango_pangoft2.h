--- pango/pangoft2.h.orig	Tue Mar 16 16:14:49 2004
+++ pango/pangoft2.h	Tue Mar 16 16:15:21 2004
@@ -23,7 +23,8 @@
 #ifndef __PANGOFT2_H__
 #define __PANGOFT2_H__
 
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 
 #include <fontconfig/fontconfig.h>
 
