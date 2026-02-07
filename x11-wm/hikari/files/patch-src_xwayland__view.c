--- src/xwayland_view.c.orig	2023-01-15 15:39:48 UTC
+++ src/xwayland_view.c
@@ -304,6 +304,7 @@ activate(struct hikari_view *view, bool active)
   struct wlr_xwayland_surface *xwayland_surface = xwayland_view->surface;
 
   wlr_xwayland_surface_activate(xwayland_surface, active);
+  wlr_xwayland_surface_restack(xwayland_surface, NULL, XCB_STACK_MODE_ABOVE);
   wlr_xwayland_set_seat(hikari_server.xwayland, hikari_server.seat);
 }
 
