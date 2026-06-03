--- src/app.rs.orig	2026-03-27 17:06:32 UTC
+++ src/app.rs
@@ -93,6 +93,7 @@ pub enum Message {
     ResumeFromSleep,
     None,
     ToggleVisibility,
+    DelayedSync,
 }
 
 impl App {
@@ -373,14 +374,11 @@ impl App {
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
 
-                    self.outputs.add(
+                    let add_task = self.outputs.add(
                         self.theme.bar_style,
                         &self.general_config.outputs,
                         self.theme.bar_position,
@@ -388,7 +386,14 @@ impl App {
                         name,
                         wl_output,
                         self.theme.scale_factor,
-                    )
+                    );
+
+                    let delay_task = Task::perform(
+                        async { tokio::time::sleep(std::time::Duration::from_millis(1000)).await },
+                        move |_| Message::DelayedSync,
+                    );
+
+                    Task::batch(vec![add_task, delay_task])
                 }
                 iced::event::wayland::OutputEvent::Removed => {
                     info!("Output destroyed");
@@ -440,6 +445,16 @@ impl App {
                         iced::platform_specific::shell::commands::layer_surface::set_exclusive_zone(info.id, height as i32)
                     })
                 }).collect::<Vec<_>>())
+            }
+            Message::DelayedSync => {
+                info!("Delayed sync executed");
+                self.outputs.sync(
+                    self.theme.bar_style,
+                    &self.general_config.outputs,
+                    self.theme.bar_position,
+                    self.general_config.layer,
+                    self.theme.scale_factor,
+                )
             }
         }
     }
