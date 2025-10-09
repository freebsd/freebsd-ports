--- winit/src/clipboard.rs.orig	2025-09-19 07:04:16 UTC
+++ winit/src/clipboard.rs
@@ -91,7 +91,7 @@ impl Clipboard {
                 })
                 .unwrap_or(State::Unavailable);
 
-        #[cfg(target_os = "linux")]
+        #[cfg(any(target_os = "linux", target_os = "freebsd"))]
         if let State::Connected { clipboard, .. } = &state {
             clipboard.init_dnd(Box::new(sender));
         }
