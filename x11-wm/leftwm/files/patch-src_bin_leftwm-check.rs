--- src/bin/leftwm-check.rs.orig	2021-05-19 07:15:38 UTC
+++ src/bin/leftwm-check.rs
@@ -37,7 +37,7 @@ async fn main() -> Result<()> {
     );
     println!(
         "\x1b[0;94m::\x1b[0m LeftWM git hash: {}",
-        git_version::git_version!()
+        git_version::git_version!(fallback = "NONE")
     );
     println!("\x1b[0;94m::\x1b[0m Loading configuration . . .");
     match load_from_file(config_file, verbose) {
