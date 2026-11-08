--- cargo-crates/pipewire-sys-0.10.0/src/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/pipewire-sys-0.10.0/src/lib.rs
@@ -19,8 +19,8 @@ mod tests {
     #[test]
     fn init() {
         unsafe {
-            pw_init(std::ptr::null_mut(), std::ptr::null_mut());
-            pw_deinit();
+            pipewire_init(std::ptr::null_mut(), std::ptr::null_mut());
+            pipewire_deinit();
         }
     }
 }
