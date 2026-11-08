--- cargo-crates/pipewire-sys-0.10.0/build.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/pipewire-sys-0.10.0/build.rs
@@ -19,6 +19,7 @@ fn main() {
         // included header files changed.
         .parse_callbacks(Box::new(bindgen::CargoCallbacks::new()))
         .size_t_is_usize(true)
+        .allowlist_function("pipewire_.*")
         .allowlist_function("pw_.*")
         .allowlist_type("pw_.*")
         .allowlist_var("pw_.*")
