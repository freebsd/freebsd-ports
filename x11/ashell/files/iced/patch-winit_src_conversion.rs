--- winit/src/conversion.rs.orig	2025-09-19 07:04:16 UTC
+++ winit/src/conversion.rs
@@ -105,7 +105,7 @@ pub fn window_attributes(
             );
     }
 
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     {
         #[cfg(feature = "x11")]
         {
