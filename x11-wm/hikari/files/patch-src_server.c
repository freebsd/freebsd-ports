--- src/server.c.orig	2022-01-13 09:15:55 UTC
+++ src/server.c
@@ -523,6 +523,9 @@ static void
 server_decoration_handler(struct wl_listener *listener, void *data)
 {
   struct wlr_server_decoration *wlr_decoration = data;
+  if (wlr_decoration->surface->role == NULL) {
+    return;
+  }
   struct hikari_view *view =
       wl_container_of(wlr_decoration->surface, view, surface);
   struct wlr_xdg_surface *xdg_surface =
