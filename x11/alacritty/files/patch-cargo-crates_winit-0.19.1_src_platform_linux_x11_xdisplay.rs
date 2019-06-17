--- cargo-crates/winit-0.19.1/src/platform/linux/x11/xdisplay.rs.orig	2019-04-08 05:29:06 UTC
+++ cargo-crates/winit-0.19.1/src/platform/linux/x11/xdisplay.rs
@@ -1,7 +1,6 @@
 use std::ptr;
 use std::fmt;
 use std::error::Error;
-use std::os::raw::c_int;
 
 use libc;
 use parking_lot::Mutex;
@@ -19,7 +18,6 @@ pub struct XConnection {
     pub xinput2: ffi::XInput2,
     pub xlib_xcb: ffi::Xlib_xcb,
     pub display: *mut ffi::Display,
-    pub x11_fd: c_int,
     pub latest_error: Mutex<Option<XError>>,
 }
 
@@ -50,11 +48,6 @@ impl XConnection {
             display
         };
 
-        // Get X11 socket file descriptor
-        let fd = unsafe {
-            (xlib.XConnectionNumber)(display)
-        };
-
         Ok(XConnection {
             xlib,
             xrandr,
@@ -63,7 +56,6 @@ impl XConnection {
             xinput2,
             xlib_xcb,
             display,
-            x11_fd: fd,
             latest_error: Mutex::new(None),
         })
     }
