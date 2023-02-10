https://lists.sr.ht/~whynothugo/shotman/%3Clel5-5qpi-wny%40FreeBSD.org%3E

--- build.rs.orig	2023-02-09 09:01:51 UTC
+++ build.rs
@@ -1,5 +1,6 @@ fn main() {
 use std::process::Command;
 fn main() {
+  if std::env::var("SHOTMAN_VERSION").is_err() {
     let version = Command::new("git")
         .args(["describe", "--tags"])
         .output()
@@ -13,4 +14,5 @@ fn main() {
         .unwrap_or(String::from("unknown")); // failed to run git
 
     println!("cargo:rustc-env=SHOTMAN_VERSION={version}");
+  }
 }
