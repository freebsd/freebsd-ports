$OpenBSD: patch-src_core_main_c,v 1.6 2018/04/26 09:19:27 jasper Exp $

extend HAVE_WAYLAND block to include opt_nested and META_TYPE_BACKEND_X11_NESTED.

Index: src/core/main.c
--- src/core/main.c.orig
+++ src/core/main.c
@@ -456,7 +456,6 @@ calculate_compositor_configuration (MetaCompositorType
   if (run_as_wayland_compositor)
     *compositor_type = META_COMPOSITOR_TYPE_WAYLAND;
   else
-#endif /* HAVE_WAYLAND */
     *compositor_type = META_COMPOSITOR_TYPE_X11;
 
 #ifdef HAVE_WAYLAND
@@ -473,6 +472,7 @@ calculate_compositor_configuration (MetaCompositorType
       *backend_gtype = META_TYPE_BACKEND_NATIVE;
       return;
     }
+#endif /* HAVE_WAYLAND */
 
 #ifdef HAVE_WAYLAND
   if (run_as_wayland_compositor)
