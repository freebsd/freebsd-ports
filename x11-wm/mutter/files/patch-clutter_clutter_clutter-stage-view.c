$OpenBSD: patch-clutter_clutter_clutter-stage-view_c,v 1.1 2021/06/04 10:56:17 ajacoutot Exp $

Index: clutter/clutter/clutter-stage-view.c
--- clutter/clutter/clutter-stage-view.c.orig
+++ clutter/clutter/clutter-stage-view.c
@@ -543,13 +543,13 @@ find_damaged_tiles (ClutterStageView      *view,
   bpp = cogl_dma_buf_handle_get_bpp (current_dma_buf_handle);
 
   cogl_framebuffer_finish (COGL_FRAMEBUFFER (priv->shadow.framebuffer));
-
+#ifdef __linux__
   if (!cogl_dma_buf_handle_sync_read_start (prev_dma_buf_handle, error))
     return NULL;
 
   if (!cogl_dma_buf_handle_sync_read_start (current_dma_buf_handle, error))
     goto err_sync_read_current;
-
+#endif
   prev_data = cogl_dma_buf_handle_mmap (prev_dma_buf_handle, error);
   if (!prev_data)
     goto err_mmap_prev;
@@ -594,7 +594,7 @@ find_damaged_tiles (ClutterStageView      *view,
             cairo_region_union_rectangle (tile_damage_region, &tile);
         }
     }
-
+#ifdef __linux__
   if (!cogl_dma_buf_handle_sync_read_end (prev_dma_buf_handle, error))
     {
       g_warning ("Failed to end DMA buffer read synchronization: %s",
@@ -608,7 +608,7 @@ find_damaged_tiles (ClutterStageView      *view,
                  (*error)->message);
       g_clear_error (error);
     }
-
+#endif
   cogl_dma_buf_handle_munmap (prev_dma_buf_handle, prev_data, NULL);
   cogl_dma_buf_handle_munmap (current_dma_buf_handle, current_data, NULL);
 
@@ -618,13 +618,16 @@ find_damaged_tiles (ClutterStageView      *view,
 
 err_mmap_current:
   cogl_dma_buf_handle_munmap (prev_dma_buf_handle, prev_data, NULL);
-
+#ifdef __linux__
 err_mmap_prev:
   cogl_dma_buf_handle_sync_read_end (current_dma_buf_handle, NULL);
 
 err_sync_read_current:
   cogl_dma_buf_handle_sync_read_end (prev_dma_buf_handle, NULL);
-
+#else
+err_mmap_prev:
+err_sync_read_current:
+#endif
   return NULL;
 }
 
