--- cargo-crates/pipewire-0.10.0/src/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/pipewire-0.10.0/src/lib.rs
@@ -180,7 +180,7 @@ pub fn init() {
 pub fn init() {
     use std::sync::OnceLock;
     static INITIALIZED: OnceLock<()> = OnceLock::new();
-    INITIALIZED.get_or_init(|| unsafe { pw_sys::pw_init(ptr::null_mut(), ptr::null_mut()) });
+    INITIALIZED.get_or_init(|| unsafe { pw_sys::pipewire_init(ptr::null_mut(), ptr::null_mut()) });
 }
 
 /// Deinitialize PipeWire
@@ -189,7 +189,7 @@ pub unsafe fn deinit() {
 /// This must only be called once during the lifetime of the process, once no PipeWire threads
 /// are running anymore and all PipeWire resources are released.
 pub unsafe fn deinit() {
-    pw_sys::pw_deinit()
+    pw_sys::pipewire_deinit()
 }
 
 #[cfg(test)]
