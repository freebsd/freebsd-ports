--- src/window.rs.orig	2018-04-23 07:37:25 UTC
+++ src/window.rs
@@ -200,6 +200,7 @@ impl Window {
             .with_transparency(true)
             .with_decorations(window_config.decorations());
         let context = ContextBuilder::new()
+            .with_srgb(true)
             .with_vsync(true);
         let window = ::glutin::GlWindow::new(window, context, &event_loop)?;
         window.show();
