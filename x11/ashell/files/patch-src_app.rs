--- src/app.rs.orig	2025-12-22 19:47:14 UTC
+++ src/app.rs
@@ -91,6 +91,7 @@ pub enum Message {
     MediaPlayer(modules::media_player::Message),
     OutputEvent((OutputEvent, WlOutput)),
     CloseAllMenus,
+    DelayedSync,
 }
 
 impl App {
@@ -378,21 +379,24 @@ impl App {
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
                         name,
                         wl_output,
                         self.theme.scale_factor,
-                    )
+                    );
+                    let delay_task = Task::perform(
+                        async { tokio::time::sleep(std::time::Duration::from_millis(1000)).await },
+                        move |_| Message::DelayedSync,
+                    );
+
+                    Task::batch(vec![add_task, delay_task])
                 }
                 iced::event::wayland::OutputEvent::Removed => {
                     info!("Output destroyed");
@@ -416,6 +420,15 @@ impl App {
                 } else {
                     Task::none()
                 }
+            }
+            Message::DelayedSync => {
+                info!("Delayed sync executed");
+                self.outputs.sync(
+                    self.theme.bar_style,
+                    &self.general_config.outputs,
+                    self.theme.bar_position,
+                    self.theme.scale_factor,
+                )
             }
         }
     }
