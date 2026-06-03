--- wgpu/src/window/x11.rs.orig	2025-09-19 07:04:16 UTC
+++ wgpu/src/window/x11.rs
@@ -145,7 +145,7 @@ pub fn get_x11_device_ids<W: Window>(window: &W) -> Op
                                         let stat =
                                             stat(Path::new("/dev/dri").join(device)).ok()?;
                                         let dev = stat.st_rdev;
-                                        return super::ids_from_dev(dev);
+                                        return super::ids_from_dev(dev.into());
                                     }
                                 }
                             }
@@ -166,6 +166,6 @@ pub fn get_x11_device_ids<W: Window>(window: &W) -> Op
         let device_fd = dri3.device_fd;
         let stat = fstat(device_fd).ok()?;
         let dev = stat.st_rdev;
-        super::ids_from_dev(dev)
+        super::ids_from_dev(dev.into())
     }
 }
