--- src/xdg.rs.orig	2026-06-11 12:03:22 UTC
+++ src/xdg.rs
@@ -1,5 +1,5 @@ use std::env;
 use std::env;
-use std::os::linux::fs::MetadataExt;
+use std::os::unix::fs::MetadataExt;
 use std::os::unix::fs::PermissionsExt;
 use std::path::PathBuf;
 
@@ -13,7 +13,7 @@ pub fn get_runtime_dir() -> Option<PathBuf> {
     let uid = unsafe { libc::geteuid() };
     (runtime_dir.is_absolute()
         && metadata.is_dir()
-        && metadata.st_uid() == uid
+        && metadata.uid() == uid
         && metadata.permissions().mode() & 0o777 == 0o700)
         .then_some(runtime_dir)
 }
