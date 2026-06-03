--- core/src/window/settings.rs.orig	2025-09-19 07:04:16 UTC
+++ core/src/window/settings.rs
@@ -7,7 +7,7 @@ mod platform;
 #[path = "settings/macos.rs"]
 mod platform;
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 #[path = "settings/linux.rs"]
 mod platform;
 
@@ -19,6 +19,7 @@ mod platform;
     target_os = "windows",
     target_os = "macos",
     target_os = "linux",
+    target_os = "freebsd",
     target_arch = "wasm32"
 )))]
 #[path = "settings/other.rs"]
