--- build.rs.orig	2026-09-29 13:29:30 UTC
+++ build.rs
@@ -1,4 +1,13 @@ fn main() {
 fn main() {
+    // Packaged builds are not run from a git checkout (and may sit inside an
+    // unrelated repository such as the ports tree), so take the version from
+    // the environment when it is provided.
+    println!("cargo::rerun-if-env-changed=HPSP_GIT_VERSION");
+    if let Ok(version) = std::env::var("HPSP_GIT_VERSION") {
+        println!("cargo::rustc-env=GIT_VERSION={version}");
+        return;
+    }
+
     let version =
         match std::process::Command::new("git").arg("describe").arg("--long").arg("--abbrev=7").arg("--tags").output() {
             Ok(output) => {
