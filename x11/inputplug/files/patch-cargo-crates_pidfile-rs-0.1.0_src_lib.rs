--- cargo-crates/pidfile-rs-0.1.0/src/lib.rs.orig	2021-10-04 13:21:00 UTC
+++ cargo-crates/pidfile-rs-0.1.0/src/lib.rs
@@ -121,7 +121,7 @@ impl Pidfile {
             Ok(c_path) => {
                 let mut old_pid: pid_t = -1;
                 let pidfn = unsafe {
-                    bsd_pidfile_open(c_path.as_ptr(), permissions.mode(), &mut old_pid)
+                    bsd_pidfile_open(c_path.as_ptr(),  permissions.mode() as mode_t, &mut old_pid)
                 };
                 if !pidfn.is_null() {
                     return Ok(Pidfile {
