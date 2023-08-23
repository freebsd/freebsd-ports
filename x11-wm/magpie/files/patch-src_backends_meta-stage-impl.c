--- src/backends/meta-stage-impl.c.orig	2023-02-13 18:12:26 UTC
+++ src/backends/meta-stage-impl.c
@@ -551,10 +551,14 @@ meta_stage_impl_redraw_view_primary (MetaStageImpl    
    * artefacts.
    */
   /* swap_region does not need damage history, set it up before that */
+#if 0
   if (use_clipped_redraw)
     swap_region = cairo_region_copy (fb_clip_region);
   else
     swap_region = cairo_region_create ();
+#else
+    swap_region = cairo_region_copy (fb_clip_region);
+#endif
 
   swap_with_damage = FALSE;
   if (has_buffer_age)
