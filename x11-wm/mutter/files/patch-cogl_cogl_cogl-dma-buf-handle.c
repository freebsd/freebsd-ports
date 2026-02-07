Index: cogl/cogl/cogl-dma-buf-handle.c
--- cogl/cogl/cogl-dma-buf-handle.c.orig	2023-07-06 10:42:04 UTC
+++ cogl/cogl/cogl-dma-buf-handle.c
@@ -37,7 +37,27 @@
 #include <errno.h>
 #include <gio/gio.h>
 #include <glib/gstdio.h>
+#ifdef __linux__
 #include <linux/dma-buf.h>
+#else
+typedef uint64_t __u64;
+
+// From https://github.com/evadot/drm-subtree or https://reviews.freebsd.org/D23085
+struct dma_buf_sync
+{
+  __u64 flags;
+};
+
+#define DMA_BUF_SYNC_READ  (1 << 0)
+#define DMA_BUF_SYNC_WRITE (2 << 0)
+#define DMA_BUF_SYNC_RW    (DMA_BUF_SYNC_READ | DMA_BUF_SYNC_WRITE)
+#define DMA_BUF_SYNC_START (0 << 2)
+#define DMA_BUF_SYNC_END   (1 << 2)
+#define DMA_BUF_SYNC_VALID_FLAGS_MASK \
+    (DMA_BUF_SYNC_RW | DMA_BUF_SYNC_END)
+#define DMA_BUF_BASE       'b'
+#define DMA_BUF_IOCTL_SYNC _IOW(DMA_BUF_BASE, 0, struct dma_buf_sync)
+#endif
 #include <sys/ioctl.h>
 #include <sys/mman.h>
 #include <unistd.h>
