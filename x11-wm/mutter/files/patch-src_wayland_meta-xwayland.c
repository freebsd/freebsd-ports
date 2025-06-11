Based on https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=258042

--- src/wayland/meta-xwayland.c.orig	2024-11-25 14:05:12 UTC
+++ src/wayland/meta-xwayland.c
@@ -598,9 +598,11 @@ open_display_sockets (MetaXWaylandManager  *manager,
 {
   int abstract_fd, unix_fd;
 
+#ifdef __linux__
   abstract_fd = bind_to_abstract_socket (display_index, error);
   if (abstract_fd < 0)
     return FALSE;
+#endif
 
   unix_fd = bind_to_unix_socket (display_index, error);
   if (unix_fd < 0)
@@ -608,6 +610,10 @@ open_display_sockets (MetaXWaylandManager  *manager,
       close (abstract_fd);
       return FALSE;
     }
+
+#ifndef __linux__
+  abstract_fd = unix_fd;
+#endif
 
   *abstract_fd_out = abstract_fd;
   *unix_fd_out = unix_fd;
