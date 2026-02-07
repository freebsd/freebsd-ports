--- wgpu/src/window.rs.orig	2025-09-19 07:04:16 UTC
+++ wgpu/src/window.rs
@@ -17,8 +17,8 @@ fn ids_from_dev(dev: u64) -> Option<(u16, u16)> {
 fn ids_from_dev(dev: u64) -> Option<(u16, u16)> {
     let path = PathBuf::from(format!(
         "/sys/dev/char/{}:{}/device",
-        major(dev),
-        minor(dev)
+        major(dev.try_into().unwrap()),
+        minor(dev.try_into().unwrap())
     ));
     let vendor = {
         let path = path.join("vendor");
