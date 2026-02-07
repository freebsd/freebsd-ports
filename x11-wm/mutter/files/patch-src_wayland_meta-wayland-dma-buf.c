Adapt changes https://gitlab.gnome.org/GNOME/mutter/-/commit/c4773089

--- src/wayland/meta-wayland-dma-buf.c.orig	2024-11-25 14:05:12 UTC
+++ src/wayland/meta-wayland-dma-buf.c
@@ -39,7 +39,9 @@
 
 #include <drm_fourcc.h>
 #include <glib/gstdio.h>
+#ifdef __linux__
 #include <linux/dma-buf.h>
+#endif
 #include <sys/ioctl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
@@ -72,6 +74,26 @@
 
 #define META_WAYLAND_DMA_BUF_MAX_FDS 4
 
+#ifndef __linux__
+/* From https://reviews.freebsd.org/D23085 */
+typedef uint64_t __u64;
+
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
+  (DMA_BUF_SYNC_RW | DMA_BUF_SYNC_END)
+#define DMA_BUF_BASE       'b'
+#define DMA_BUF_IOCTL_SYNC _IOW(DMA_BUF_BASE, 0, struct dma_buf_sync)
+#endif
+
 /* Compatible with zwp_linux_dmabuf_feedback_v1.tranche_flags */
 typedef enum _MetaWaylandDmaBufTrancheFlags
 {
@@ -863,7 +885,9 @@ typedef struct _MetaWaylandDmaBufSource
   gpointer user_data;
 
   gpointer fd_tags[META_WAYLAND_DMA_BUF_MAX_FDS];
+#ifdef __linux__
   int owned_sync_fd[META_WAYLAND_DMA_BUF_MAX_FDS];
+#endif
 } MetaWaylandDmaBufSource;
 
 static gboolean
@@ -898,11 +922,13 @@ meta_wayland_dma_buf_source_dispatch (GSource     *bas
   for (i = 0; i < META_WAYLAND_DMA_BUF_MAX_FDS; i++)
     {
       gpointer fd_tag = source->fd_tags[i];
-      int fd;
 
       if (!fd_tag)
         continue;
 
+#ifdef __linux__
+      int fd;
+
       fd = source->owned_sync_fd[i];
       if (fd < 0)
         fd = dma_buf->fds[i];
@@ -912,10 +938,19 @@ meta_wayland_dma_buf_source_dispatch (GSource     *bas
           ready = FALSE;
           continue;
         }
+#else
+      if (!is_fd_readable (dma_buf->fds[i]))
+        {
+          ready = FALSE;
+          continue;
+        }
+#endif
 
       g_source_remove_unix_fd (&source->base, fd_tag);
       source->fd_tags[i] = NULL;
+#ifdef __linux__
       g_clear_fd (&source->owned_sync_fd[i], NULL);
+#endif
     }
 
   if (!ready)
@@ -942,7 +977,9 @@ meta_wayland_dma_buf_source_finalize (GSource *base)
         {
           g_source_remove_unix_fd (&source->base, fd_tag);
           source->fd_tags[i] = NULL;
+#ifdef __linux__
           g_clear_fd (&source->owned_sync_fd[i], NULL);
+#endif
         }
     }
 
@@ -960,7 +997,6 @@ create_source (MetaWaylandBuffer               *buffer
                gpointer                         user_data)
 {
   MetaWaylandDmaBufSource *source;
-  int i;
 
   source =
     (MetaWaylandDmaBufSource *) g_source_new (&meta_wayland_dma_buf_source_funcs,
@@ -971,12 +1007,17 @@ create_source (MetaWaylandBuffer               *buffer
   source->dispatch = dispatch;
   source->user_data = user_data;
 
+#ifdef __linux__
+  int i;
+
   for (i = 0; i < META_WAYLAND_DMA_BUF_MAX_FDS; i++)
     source->owned_sync_fd[i] = -1;
+#endif
 
   return source;
 }
 
+#ifdef __linux__
 static int
 get_sync_file (int dma_buf_fd)
 {
@@ -994,6 +1035,7 @@ get_sync_file (int dma_buf_fd)
 
   return -1;
 }
+#endif
 
 /**
  * meta_wayland_dma_buf_create_source:
@@ -1034,9 +1076,11 @@ meta_wayland_dma_buf_create_source (MetaWaylandBuffer 
       if (!source)
         source = create_source (buffer, dispatch, user_data);
 
+#ifdef __linux__
       source->owned_sync_fd[i] = get_sync_file (fd);
       if (source->owned_sync_fd[i] >= 0)
         fd = source->owned_sync_fd[i];
+#endif
 
       source->fd_tags[i] = g_source_add_unix_fd (&source->base, fd, G_IO_IN);
     }
@@ -1075,7 +1119,9 @@ meta_wayland_drm_syncobj_create_source (MetaWaylandBuf
     return NULL;
 
   source->fd_tags[0] = g_source_add_unix_fd (&source->base, sync_fd, G_IO_IN);
+#ifdef __linux__
   source->owned_sync_fd[0] = g_steal_fd (&sync_fd);
+#endif
 
   return &source->base;
 }
