--- pango/opentype/ftxopen.h.orig	Tue Mar 16 16:19:27 2004
+++ pango/opentype/ftxopen.h	Tue Mar 16 16:19:45 2004
@@ -22,7 +22,8 @@
 #ifndef FTXOPEN_H
 #define FTXOPEN_H
 
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 
 #ifdef __cplusplus
 extern "C" {
