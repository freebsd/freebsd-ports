--- winit/src/program.rs.orig	2025-09-19 07:04:16 UTC
+++ winit/src/program.rs
@@ -773,7 +773,7 @@ async fn run_instance<'a, P, C>(
 
     let mut platform_specific_handler =
         crate::platform_specific::PlatformSpecific::default();
-    #[cfg(all(feature = "wayland", target_os = "linux"))]
+    #[cfg(all(feature = "wayland", any(target_os = "linux", target_os = "freebsd")))]
     if is_wayland {
         platform_specific_handler = platform_specific_handler.with_wayland(
             control_sender.clone(),
