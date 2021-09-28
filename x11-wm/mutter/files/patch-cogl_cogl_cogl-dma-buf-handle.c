$OpenBSD: patch-cogl_cogl_cogl-dma-buf-handle_c,v 1.2 2021/06/04 10:56:17 ajacoutot Exp $

Index: cogl/cogl/cogl-dma-buf-handle.c
--- cogl/cogl/cogl-dma-buf-handle.c.orig
+++ cogl/cogl/cogl-dma-buf-handle.c
@@ -36,8 +36,10 @@
 
 #include <errno.h>
 #include <gio/gio.h>
+#ifdef __linux__
 #include <linux/dma-buf.h>
 #include <sys/ioctl.h>
+#endif
 #include <sys/mman.h>
 #include <unistd.h>
 
@@ -101,6 +103,7 @@ cogl_dma_buf_handle_free (CoglDmaBufHandle *dmabuf_han
   g_free (dmabuf_handle);
 }
 
+#ifdef __linux__
 static gboolean
 sync_read (CoglDmaBufHandle  *dmabuf_handle,
            uint64_t           start_or_end,
@@ -147,6 +150,7 @@ cogl_dma_buf_handle_sync_read_end (CoglDmaBufHandle  *
 {
   return sync_read (dmabuf_handle, DMA_BUF_SYNC_END, error);
 }
+#endif
 
 gpointer
 cogl_dma_buf_handle_mmap (CoglDmaBufHandle  *dmabuf_handle,
