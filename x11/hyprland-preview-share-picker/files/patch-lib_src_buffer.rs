--- lib/src/buffer.rs.orig	2026-09-29 14:42:38 UTC
+++ lib/src/buffer.rs
@@ -11,6 +11,44 @@ use crate::error::Error;
 
 use crate::error::Error;
 
+/// Anonymous shared-memory file backing a frame. The memfd crate only supports
+/// Linux and Android; FreeBSD (13.0 and later) provides memfd_create(2) in libc.
+#[cfg(not(target_os = "freebsd"))]
+type BufferFile = memfd::Memfd;
+#[cfg(target_os = "freebsd")]
+type BufferFile = std::fs::File;
+
+#[cfg(not(target_os = "freebsd"))]
+fn create_buffer_file() -> Result<BufferFile, Box<dyn std::error::Error + Sync + Send>> {
+    Ok(memfd::MemfdOptions::default().create("buffer")?)
+}
+
+#[cfg(target_os = "freebsd")]
+fn create_buffer_file() -> Result<BufferFile, Box<dyn std::error::Error + Sync + Send>> {
+    use std::os::fd::FromRawFd;
+
+    unsafe extern "C" {
+        fn memfd_create(name: *const std::ffi::c_char, flags: std::ffi::c_uint) -> std::ffi::c_int;
+    }
+    const MFD_CLOEXEC: std::ffi::c_uint = 0x0000_0001;
+    let fd = unsafe { memfd_create(c"buffer".as_ptr(), MFD_CLOEXEC) };
+    if fd < 0 {
+        return Err(std::io::Error::last_os_error().into());
+    }
+    // memfd_create returned a new descriptor that nothing else owns.
+    Ok(unsafe { std::fs::File::from_raw_fd(fd) })
+}
+
+#[cfg(not(target_os = "freebsd"))]
+fn buffer_file(fd: &BufferFile) -> &std::fs::File {
+    fd.as_file()
+}
+
+#[cfg(target_os = "freebsd")]
+fn buffer_file(fd: &BufferFile) -> &std::fs::File {
+    fd
+}
+
 #[derive(Debug)]
 pub struct Buffer {
     pub buffer: WlBuffer,
@@ -18,7 +56,7 @@ pub struct Buffer {
     pub height: u32,
     pub stride: u32,
     pub format: Format,
-    fd: memfd::Memfd,
+    fd: BufferFile,
 }
 
 impl Buffer {
@@ -35,9 +73,9 @@ impl Buffer {
         handle: &QueueHandle<T>,
         udata: K,
     ) -> Result<Self, Error> {
-        let mfd = memfd::MemfdOptions::default().create("buffer").map_err(|err| Error::BufferCreate(err.into()))?;
-        mfd.as_file().set_len((width * height * 4) as u64).map_err(|err| Error::BufferCreate(err.into()))?;
-        let pool = shm.create_pool(mfd.as_file().as_fd(), (width * height * 4) as i32, handle, udata.clone());
+        let mfd = create_buffer_file().map_err(Error::BufferCreate)?;
+        buffer_file(&mfd).set_len((width * height * 4) as u64).map_err(|err| Error::BufferCreate(err.into()))?;
+        let pool = shm.create_pool(buffer_file(&mfd).as_fd(), (width * height * 4) as i32, handle, udata.clone());
         let buffer = pool.create_buffer(0, width as i32, height as i32, stride as i32, format, handle, udata);
 
         pool.destroy();
@@ -48,7 +86,7 @@ impl Buffer {
     pub fn get_bytes(&self) -> Result<Vec<u8>, Error> {
         // let mut file = unsafe { File::from_raw_fd(self.fd) };
         let mut bytes = Vec::new();
-        self.fd.as_file().read_to_end(&mut bytes).map_err(|err| Error::BufferRead(err))?;
+        buffer_file(&self.fd).read_to_end(&mut bytes).map_err(|err| Error::BufferRead(err))?;
         Ok(bytes)
     }
 
