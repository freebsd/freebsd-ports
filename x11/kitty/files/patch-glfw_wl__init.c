--- glfw/wl_init.c.orig	1979-11-29 23:00:00 UTC
+++ glfw/wl_init.c
@@ -36,6 +36,7 @@
 #include "wayland-text-input-unstable-v3-client-protocol.h"
 
 #include <stdio.h>
+#include <errno.h>
 #include <stdlib.h>
 #include <string.h>
 #include <sys/mman.h>
@@ -637,6 +638,7 @@ get_socket_peer_pid(int fd) {
 
 static pid_t
 get_socket_peer_pid(int fd) {
+    (void)fd;
 #ifdef __linux__
     struct ucred ucred;
     socklen_t len = sizeof(struct ucred);
