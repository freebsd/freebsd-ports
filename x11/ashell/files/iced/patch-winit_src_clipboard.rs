--- winit/src/clipboard.rs.orig	2025-12-02 15:56:28 UTC
+++ winit/src/clipboard.rs
@@ -92,7 +92,7 @@ impl Clipboard {
                 })
                 .unwrap_or(State::Unavailable);
 
-        #[cfg(target_os = "linux")]
+        #[cfg(any(target_os = "linux", target_os = "freebsd"))]
         if let State::Connected { clipboard, .. } = &state {
             clipboard.init_dnd(Box::new(sender));
         }
