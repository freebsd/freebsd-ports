--- winit/src/program.rs.orig	2025-12-02 15:56:28 UTC
+++ winit/src/program.rs
@@ -776,7 +776,7 @@ async fn run_instance<'a, P, C>(
 
     let mut platform_specific_handler =
         crate::platform_specific::PlatformSpecific::default();
-    #[cfg(all(feature = "wayland", target_os = "linux"))]
+    #[cfg(all(feature = "wayland", any(target_os = "linux", target_os = "freebsd")))]
     if is_wayland {
         platform_specific_handler = platform_specific_handler.with_wayland(
             control_sender.clone(),
