$OpenBSD: patch-src_compositor_compositor_c,v 1.2 2017/05/21 17:48:10 jasper Exp $

undefined reference to `meta_dnd_wayland_handle_begin_modal'

Index: src/compositor/compositor.c
--- src/compositor/compositor.c.orig
+++ src/compositor/compositor.c
@@ -383,6 +383,7 @@ meta_begin_modal_for_plugin (MetaCompositor   *composi
                          meta_plugin_get_screen (plugin),
                          display->grab_window, display->grab_op);
 
+#ifdef HAVE_WAYLAND
   if (meta_is_wayland_compositor ())
     {
       meta_display_sync_wayland_input_focus (display);
@@ -392,6 +393,7 @@ meta_begin_modal_for_plugin (MetaCompositor   *composi
       meta_dnd_wayland_handle_begin_modal (compositor);
 #endif
     }
+#endif
 
   return TRUE;
 }
