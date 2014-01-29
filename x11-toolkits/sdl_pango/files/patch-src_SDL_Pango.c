--- src/SDL_Pango.c~	2013-12-31 14:26:31.000000000 +0000
+++ src/SDL_Pango.c	2013-12-31 14:22:36.000000000 +0000
@@ -330,6 +330,11 @@
     @param *rect [in] Draw on this area
     @param baseline [in] Horizontal location of glyphs
 */
+void SDLPango_CopyFTBitmapToSurface(
+    const FT_Bitmap *bitmap,
+    SDL_Surface *surface,
+    const SDLPango_Matrix *matrix,
+    SDL_Rect *rect);
 static void
 drawGlyphString(
     SDLPango_Context *context,
