Revert a couple of commits in the winit crate to workaround freezes
on X11 when there are no X input events.

https://github.com/rust-windowing/winit/commit/0019ff210c4d0d29b844b69e1924679754f0b65c
https://github.com/rust-windowing/winit/commit/9ea2810b4615f21563b001949fe7f97bb91d3bea
https://github.com/jwilm/alacritty/issues/2217

--- cargo-crates/winit-0.19.1/src/platform/linux/x11/mod.rs.orig	2019-04-08 05:29:06 UTC
+++ cargo-crates/winit-0.19.1/src/platform/linux/x11/mod.rs
@@ -19,13 +19,6 @@ use std::collections::HashMap;
 use std::ffi::CStr;
 use std::ops::Deref;
 use std::os::raw::*;
-use libc::{select, fd_set, FD_SET, FD_ZERO, FD_ISSET, EINTR, EINVAL, ENOMEM, EBADF};
-#[cfg(target_os = "linux")]
-use libc::__errno_location;
-#[cfg(target_os = "freebsd")]
-use libc::__error as __errno_location;
-#[cfg(any(target_os = "netbsd", target_os = "openbsd"))]
-use libc::__errno as __errno_location;
 use std::sync::{Arc, mpsc, Weak};
 use std::sync::atomic::{self, AtomicBool};
 
@@ -192,70 +185,6 @@ impl EventsLoop {
         }
     }
 
-    unsafe fn poll_one_event(&mut self, event_ptr : *mut ffi::XEvent) -> bool {
-        // This function is used to poll and remove a single event
-        // from the Xlib event queue in a non-blocking, atomic way.
-        // XCheckIfEvent is non-blocking and removes events from queue.
-        // XNextEvent can't be used because it blocks while holding the
-        // global Xlib mutex.
-        // XPeekEvent does not remove events from the queue.
-        unsafe extern "C" fn predicate(
-            _display: *mut ffi::Display,
-            _event: *mut ffi::XEvent,
-            _arg : *mut c_char)  -> c_int {
-            // This predicate always returns "true" (1) to accept all events
-            1
-        }
-
-        let result = (self.xconn.xlib.XCheckIfEvent)(
-            self.xconn.display,
-            event_ptr,
-            Some(predicate),
-            std::ptr::null_mut());
-
-        result != 0
-    }
-
-    unsafe fn wait_for_input(&mut self) {
-        // XNextEvent can not be used in multi-threaded applications
-        // because it is blocking for input while holding the global
-        // Xlib mutex.
-        // To work around this issue, first flush the X11 display, then
-        // use select(2) to wait for input to arrive
-        loop {
-            // First use XFlush to flush any buffered x11 requests
-            (self.xconn.xlib.XFlush)(self.xconn.display);
-
-            // Then use select(2) to wait for input data
-            let mut fds : fd_set = mem::uninitialized();
-            FD_ZERO(&mut fds);
-            FD_SET(self.xconn.x11_fd, &mut fds);
-            let err = select(
-                self.xconn.x11_fd + 1,
-                &mut fds, // read fds
-                std::ptr::null_mut(), // write fds
-                std::ptr::null_mut(), // except fds (could be used to detect errors)
-                std::ptr::null_mut()); // timeout
-
-            if err < 0 {
-                let errno_ptr = __errno_location();
-                let errno = *errno_ptr;
-
-                if errno == EINTR {
-                    // try again if errno is EINTR
-                    continue;
-                }
-
-                assert!(errno == EBADF || errno == EINVAL || errno == ENOMEM);
-                panic!("select(2) returned fatal error condition");
-            }
-
-            if FD_ISSET(self.xconn.x11_fd, &mut fds) {
-                break;
-            }
-        }
-    }
-
     pub fn poll_events<F>(&mut self, mut callback: F)
         where F: FnMut(Event)
     {
@@ -263,9 +192,13 @@ impl EventsLoop {
         loop {
             // Get next event
             unsafe {
-                if !self.poll_one_event(&mut xev) {
+                // Ensure XNextEvent won't block
+                let count = (self.xconn.xlib.XPending)(self.xconn.display);
+                if count == 0 {
                     break;
                 }
+
+                (self.xconn.xlib.XNextEvent)(self.xconn.display, &mut xev);
             }
             self.process_event(&mut xev, &mut callback);
         }
@@ -277,12 +210,7 @@ impl EventsLoop {
         let mut xev = unsafe { mem::uninitialized() };
 
         loop {
-            unsafe {
-                while !self.poll_one_event(&mut xev) {
-                    // block until input is available
-                    self.wait_for_input();
-                }
-            };
+            unsafe { (self.xconn.xlib.XNextEvent)(self.xconn.display, &mut xev) }; // Blocks as necessary
 
             let mut control_flow = ControlFlow::Continue;
 
