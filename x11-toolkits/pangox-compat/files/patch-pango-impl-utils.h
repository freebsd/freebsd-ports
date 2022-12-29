--- pango-impl-utils.h.orig	2012-08-27 23:19:32 UTC
+++ pango-impl-utils.h
@@ -174,6 +174,11 @@ pango_glyph_string_reverse_range (PangoGlyphString *gl
     }
 }
 
+/* From pango-font-private.h */
+PangoFontMetrics *pango_font_metrics_new (void);
+
+/* From pango-utils-private.h */
+char *pango_config_key_get (const char *key);
 
 G_END_DECLS
 
