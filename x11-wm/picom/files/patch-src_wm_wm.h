# Official fixes for 32-bit compilation
--- src/wm/wm.h.orig	2024-09-28 23:22:13 UTC
+++ src/wm/wm.h
@@ -63,7 +63,7 @@ typedef struct wm_treeid {
 typedef struct wm_treeid {
 	/// The generation of the window ID. This is used to detect if the window ID is
 	/// reused. Inherited from the wm_tree at cr
-	uint64_t gen;
+	alignas(8) uint64_t gen;
 	/// The X window ID.
 	xcb_window_t x;
 
