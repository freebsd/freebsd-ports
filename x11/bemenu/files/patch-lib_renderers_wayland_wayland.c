--- lib/renderers/wayland/wayland.c.orig	2019-03-07 08:35:43 UTC
+++ lib/renderers/wayland/wayland.c
@@ -266,7 +266,7 @@ constructor(struct bm_menu *menu)
         wl_list_insert(&wayland->windows, &window->link);
     }
 
-    if (!efd && (efd = epoll_create(EPOLL_CLOEXEC)) < 0)
+    if (!efd && (efd = epoll_create1(EPOLL_CLOEXEC)) < 0)
         goto fail;
 
     struct epoll_event ep;
