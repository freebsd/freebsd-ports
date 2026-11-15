--- src/xdg.rs.orig	2026-11-14 10:39:39 UTC
+++ src/xdg.rs
@@ -1,6 +1,6 @@ use std::fs::{DirBuilder, Metadata};
 use std::env;
 use std::fs::{DirBuilder, Metadata};
-use std::os::linux::fs::MetadataExt;
+use std::os::unix::fs::MetadataExt;
 use std::os::unix::fs::{DirBuilderExt, PermissionsExt};
 use std::path::PathBuf;
 
@@ -19,7 +19,7 @@ pub fn is_private_dir(metadata: &Metadata) -> bool {
 /// A directory owned by the effective user with mode 0700.
 pub fn is_private_dir(metadata: &Metadata) -> bool {
     let uid = unsafe { libc::geteuid() };
-    metadata.is_dir() && metadata.st_uid() == uid && metadata.permissions().mode() & 0o777 == 0o700
+    metadata.is_dir() && metadata.uid() == uid && metadata.permissions().mode() & 0o777 == 0o700
 }
 
 pub fn fallback_dir() -> PathBuf {
