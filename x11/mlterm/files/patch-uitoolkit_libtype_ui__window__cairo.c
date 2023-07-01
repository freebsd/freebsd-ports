--- uitoolkit/libtype/ui_window_cairo.c.orig	2023-07-01 12:37:30 UTC
+++ uitoolkit/libtype/ui_window_cairo.c
@@ -54,7 +54,7 @@ static void adjust_glyphs(ui_font_t *font, cairo_glyph
 
 static void flush_glyphs(cairo_t *cr) {
   if (num_glyph_buf > 0) {
-    u_long pixel = cairo_get_user_data(cr, (cairo_user_data_key_t*)2);
+    u_long pixel = (u_long)cairo_get_user_data(cr, (cairo_user_data_key_t*)2);
 
     cairo_set_scaled_font(cr, cairo_get_user_data(cr, (cairo_user_data_key_t*)1));
     cairo_set_source_rgba(cr,
