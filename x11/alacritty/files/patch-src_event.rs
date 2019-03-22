Let Alacritty open new instances in the shell's working directory
as long as linprocfs(5) is mounted on /compat/linux/proc.

https://github.com/jwilm/alacritty/commit/0ec4bd28dadcf476baf6180af7cf93bea9214f19

--- src/event.rs.orig	2019-02-11 23:59:21 UTC
+++ src/event.rs
@@ -172,7 +172,11 @@ impl<'a, N: Notify + 'a> input::ActionContext for Acti
 
         #[cfg(unix)]
         let args = {
-            if let Ok(path) = fs::read_link(format!("/proc/{}/cwd", unsafe { tty::PID })) {
+            #[cfg(not(target_os = "freebsd"))]
+            let proc_prefix = "";
+            #[cfg(target_os = "freebsd")]
+            let proc_prefix = "/compat/linux";
+            if let Ok(path) = fs::read_link(format!("{}/proc/{}/cwd", proc_prefix, unsafe { tty::PID })) {
                 vec!["--working-directory".into(), path]
             } else {
                 Vec::new()
