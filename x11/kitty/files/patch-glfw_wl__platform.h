--- glfw/wl_platform.h.orig	1979-11-29 21:00:00 UTC
+++ glfw/wl_platform.h
@@ -130,6 +130,10 @@ typedef enum WaylandWindowState {
     TOPLEVEL_STATE_TILED_TOP = 64,
     TOPLEVEL_STATE_TILED_BOTTOM = 128,
     TOPLEVEL_STATE_SUSPENDED = 256,
+    TOPLEVEL_STATE_CONSTRAINED_LEFT = 512,
+    TOPLEVEL_STATE_CONSTRAINED_RIGHT = 1024,
+    TOPLEVEL_STATE_CONSTRAINED_TOP = 2048,
+    TOPLEVEL_STATE_CONSTRAINED_BOTTOM = 4096,
 } WaylandWindowState;
 
 typedef struct glfw_wl_xdg_activation_request {
