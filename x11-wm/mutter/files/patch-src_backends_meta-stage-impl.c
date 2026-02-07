https://gitlab.gnome.org/GNOME/mutter/-/issues/2103

--- src/backends/meta-stage-impl.c.orig	2024-11-25 14:05:12 UTC
+++ src/backends/meta-stage-impl.c
@@ -612,9 +612,13 @@ meta_stage_impl_redraw_view_primary (MetaStageImpl    
    * artefacts.
    */
   /* swap_region does not need damage history, set it up before that */
+#if 0
   if (!use_clipped_redraw)
     swap_region = mtk_region_create ();
   else if (clutter_stage_view_has_shadowfb (stage_view))
+#else
+  if (clutter_stage_view_has_shadowfb (stage_view))
+#endif
     swap_region = mtk_region_ref (fb_clip_region);
   else
     swap_region = mtk_region_copy (fb_clip_region);
