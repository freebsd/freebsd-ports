$OpenBSD: patch-cogl_cogl_cogl-dma-buf-handle_h,v 1.2 2021/06/04 10:56:17 ajacoutot Exp $

Index: cogl/cogl/cogl-dma-buf-handle.h
--- cogl/cogl/cogl-dma-buf-handle.h.orig
+++ cogl/cogl/cogl-dma-buf-handle.h
@@ -63,6 +63,7 @@ cogl_dma_buf_handle_new (CoglFramebuffer *framebuffer,
 COGL_EXPORT void
 cogl_dma_buf_handle_free (CoglDmaBufHandle *dmabuf_handle);
 
+# ifdef __linux__
 COGL_EXPORT gboolean
 cogl_dma_buf_handle_sync_read_start (CoglDmaBufHandle  *dmabuf_handle,
                                      GError           **error);
@@ -70,7 +71,7 @@ cogl_dma_buf_handle_sync_read_start (CoglDmaBufHandle 
 COGL_EXPORT gboolean
 cogl_dma_buf_handle_sync_read_end (CoglDmaBufHandle  *dmabuf_handle,
                                    GError           **error);
-
+# endif
 COGL_EXPORT gpointer
 cogl_dma_buf_handle_mmap (CoglDmaBufHandle  *dmabuf_handle,
                           GError           **error);
