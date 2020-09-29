$OpenBSD: patch-src_backends_meta-egl_c,v 1.2 2018/04/26 09:19:27 jasper Exp $

Revert non-portable portion of:
From b7b5fb293d1de3af9e533f2063749fde7a790945 Mon Sep 17 00:00:00 2001
From: Daniel Stone <daniels@collabora.com>
Date: Tue, 11 Jul 2017 16:03:26 +0100
Subject: [PATCH] wayland: Add zwp_linux_dmabuf_v1 support

Index: src/backends/meta-egl.c
--- src/backends/meta-egl.c.orig	2020-09-07 19:18:23 UTC
+++ src/backends/meta-egl.c
@@ -69,8 +69,6 @@ struct _MetaEgl
   PFNEGLSTREAMCONSUMERACQUIREKHRPROC eglStreamConsumerAcquireKHR;
   PFNEGLSTREAMCONSUMERACQUIREATTRIBNVPROC eglStreamConsumerAcquireAttribNV;
 
-  PFNEGLQUERYDMABUFFORMATSEXTPROC eglQueryDmaBufFormatsEXT;
-  PFNEGLQUERYDMABUFMODIFIERSEXTPROC eglQueryDmaBufModifiersEXT;
 };
 
 G_DEFINE_TYPE (MetaEgl, meta_egl, G_TYPE_OBJECT)
@@ -1019,51 +1017,6 @@ meta_egl_stream_consumer_acquire (MetaEgl     *egl,
   return TRUE;
 }
 
-gboolean
-meta_egl_query_dma_buf_formats (MetaEgl   *egl,
-                                EGLDisplay display,
-                                EGLint     max_formats,
-                                EGLint    *formats,
-                                EGLint    *num_formats,
-                                GError   **error)
-{
-  if (!is_egl_proc_valid (egl->eglQueryDmaBufFormatsEXT, error))
-    return FALSE;
-
-  if (!egl->eglQueryDmaBufFormatsEXT (display, max_formats, formats,
-                                      num_formats))
-    {
-      set_egl_error (error);
-      return FALSE;
-    }
-
-    return TRUE;
-}
-
-gboolean
-meta_egl_query_dma_buf_modifiers (MetaEgl      *egl,
-                                  EGLDisplay    display,
-                                  EGLint        format,
-                                  EGLint        max_modifiers,
-                                  EGLuint64KHR *modifiers,
-                                  EGLBoolean   *external_only,
-                                  EGLint       *num_modifiers,
-                                  GError      **error)
-{
-  if (!is_egl_proc_valid (egl->eglQueryDmaBufModifiersEXT, error))
-    return FALSE;
-
-  if (!egl->eglQueryDmaBufModifiersEXT (display, format, max_modifiers,
-                                        modifiers, external_only,
-                                        num_modifiers))
-    {
-      set_egl_error (error);
-      return FALSE;
-    }
-
-    return TRUE;
-}
-
 #define GET_EGL_PROC_ADDR(proc) \
   egl->proc = (void *) eglGetProcAddress (#proc);
 
@@ -1100,8 +1053,6 @@ meta_egl_constructed (GObject *object)
   GET_EGL_PROC_ADDR (eglStreamConsumerAcquireKHR);
   GET_EGL_PROC_ADDR (eglStreamConsumerAcquireAttribNV);
 
-  GET_EGL_PROC_ADDR (eglQueryDmaBufFormatsEXT);
-  GET_EGL_PROC_ADDR (eglQueryDmaBufModifiersEXT);
 }
 
 #undef GET_EGL_PROC_ADDR
