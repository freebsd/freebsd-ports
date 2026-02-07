Based on https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=258042

--- src/wayland/meta-wayland-buffer.c.orig	2024-11-25 14:05:12 UTC
+++ src/wayland/meta-wayland-buffer.c
@@ -228,6 +228,7 @@ shm_to_drm_format (enum wl_shm_format format)
   return format;
 }
 
+#ifdef HAVE_NATIVE_BACKEND
 static const char *
 shm_format_to_string (MetaDrmFormatBuf   *format_buf,
                       enum wl_shm_format  shm_format)
@@ -237,6 +238,7 @@ shm_format_to_string (MetaDrmFormatBuf   *format_buf,
   drm_format = shm_to_drm_format (shm_format);
   return meta_drm_format_to_string (format_buf, drm_format);
 }
+#endif
 
 static const MetaFormatInfo *
 get_supported_shm_format_info (uint32_t shm_format)
@@ -409,7 +411,9 @@ shm_buffer_attach (MetaWaylandBuffer  *buffer,
   int stride, width, height;
   MetaMultiTextureFormat multi_format;
   CoglPixelFormat cogl_format;
+#ifdef HAVE_NATIVE_BACKEND
   MetaDrmFormatBuf format_buf;
+#endif
   uint32_t shm_format;
   const MetaFormatInfo *format_info;
 
@@ -430,6 +434,7 @@ shm_buffer_attach (MetaWaylandBuffer  *buffer,
   cogl_format = format_info->cogl_format;
   multi_format = format_info->multi_texture_format;
 
+#ifdef HAVE_NATIVE_BACKEND
   meta_topic (META_DEBUG_WAYLAND,
               "[wl-shm] wl_buffer@%u wl_shm_format %s "
               "-> MetaMultiTextureFormat %s / CoglPixelFormat %s",
@@ -437,6 +442,7 @@ shm_buffer_attach (MetaWaylandBuffer  *buffer,
               shm_format_to_string (&format_buf, shm_format),
               meta_multi_texture_format_to_string (multi_format),
               cogl_pixel_format_to_string (cogl_format));
+#endif
 
   if (*texture &&
       meta_multi_texture_get_width (*texture) == width &&
