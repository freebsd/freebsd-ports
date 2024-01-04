The g_critical() function will core dump if critical errors are marked
fatal (which they are in xss-lock).  Instead, log as informational and
exit.  Thanks to Tomáš Janoušek for the bug report and original patch.

--- src/xss-lock.c.orig	2014-03-02 10:46:32 UTC
+++ src/xss-lock.c
@@ -158,8 +158,10 @@ screensaver_event_cb(xcb_connection_t *connection, xcb
 {
     uint8_t event_type;
     
-    if (!event)
-        g_critical("X connection lost; exiting.");
+    if (!event) {
+        g_info("X connection lost; exiting.");
+        exit(EXIT_FAILURE);
+    }
     
     event_type = XCB_EVENT_RESPONSE_TYPE(event);
     if (event_type == 0) {
