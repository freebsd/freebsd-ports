--- plugins/fuse.c.orig	2010-05-21 11:18:14 UTC
+++ plugins/fuse.c
@@ -28,6 +28,8 @@
 #include <errno.h>
 #include <poll.h>
 #include <signal.h>
+#include <sys/types.h>
+#include <sys/param.h>
 #include <sys/mount.h>
 #include <fuse.h>
 #include <fuse_lowlevel.h>
