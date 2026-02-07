--- pangox.c.orig	2021-01-16 11:31:26 UTC
+++ pangox.c
@@ -279,7 +279,7 @@ pango_x_font_class_init (PangoXFontClass *class)
 
   font_class->describe = pango_x_font_describe;
   font_class->get_coverage = pango_x_font_get_coverage;
-  font_class->find_shaper = pango_x_font_find_shaper;
+  /* font_class->find_shaper = pango_x_font_find_shaper; */
   font_class->get_glyph_extents = pango_x_font_get_glyph_extents;
   font_class->get_metrics = pango_x_font_get_metrics;
   font_class->get_font_map = pango_x_font_get_font_map;
@@ -1373,12 +1373,11 @@ pango_x_font_find_shaper (PangoFont     *font G_GNUC_U
 			  PangoLanguage *language,
 			  guint32        ch)
 {
-  PangoMap *shape_map = NULL;
-  PangoScript script;
-
-  shape_map = pango_x_get_shaper_map (language);
-  script = pango_script_for_unichar (ch);
-  return (PangoEngineShape *)pango_map_get_engine (shape_map, script);
+  static PangoEngineShape *shaper;
+  if (g_once_init_enter (&shaper))
+    g_once_init_leave (&shaper,
+		       _pango_basic_x_script_engine_create("BasicScriptEngineXCompat"));
+  return shaper;
 }
 
 /* Utility functions */
