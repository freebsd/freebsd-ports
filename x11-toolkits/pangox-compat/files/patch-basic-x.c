--- basic-x.c.orig	2012-08-27 23:19:32 UTC
+++ basic-x.c
@@ -556,9 +556,11 @@ basic_engine_shape (PangoEngineShape *engine G_GNUC_UN
 basic_engine_shape (PangoEngineShape *engine G_GNUC_UNUSED,
 		    PangoFont        *font,
 		    const char       *text,
-		    gint              length,
+		    unsigned int      length,
 		    const PangoAnalysis *analysis,
-		    PangoGlyphString *glyphs)
+		    PangoGlyphString *glyphs,
+		    const char       *paragraph_text G_GNUC_UNUSED,
+		    unsigned int      paragraph_length G_GNUC_UNUSED)
 {
   int n_chars;
   int i;
