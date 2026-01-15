--- src/app.rs.orig	2025-12-22 19:47:14 UTC
+++ src/app.rs
@@ -378,12 +378,9 @@ impl App {
                 }
             },
             Message::OutputEvent((event, wl_output)) => match event {
-                iced::event::wayland::OutputEvent::Created(info) => {
-                    info!("Output created: {info:?}");
-                    let name = info
-                        .as_ref()
-                        .and_then(|info| info.description.as_deref())
-                        .unwrap_or("");
+                iced::event::wayland::OutputEvent::InfoUpdate(info) => {
+                    info!("Output updated: {info:?}");
+                    let name = info.description.as_deref().unwrap_or("");
 
                     self.outputs.add(
                         self.theme.bar_style,
