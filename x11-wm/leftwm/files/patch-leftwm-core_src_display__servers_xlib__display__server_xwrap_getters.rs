--- leftwm-core/src/display_servers/xlib_display_server/xwrap/getters.rs.orig	2021-12-12 17:42:31 UTC
+++ leftwm-core/src/display_servers/xlib_display_server/xwrap/getters.rs
@@ -575,7 +575,7 @@ impl XWrap {
             if status == 0 {
                 return Err(XlibError::FailedStatus);
             }
-            if let Ok(s) = CString::from_raw(text_prop.value.cast::<i8>()).into_string() {
+            if let Ok(s) = CString::from_raw(text_prop.value.cast::<nix::libc::c_char>()).into_string() {
                 return Ok(s);
             }
         };
