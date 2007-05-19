--- plugins/fuse.c.orig	Mon Apr  2 14:15:28 2007
+++ plugins/fuse.c	Mon May  7 20:07:09 2007
@@ -28,6 +28,8 @@
 #include <errno.h>
 #include <poll.h>
 #include <signal.h>
+#include <sys/types.h>
+#include <sys/param.h>
 #include <sys/mount.h>
 #include <fuse.h>
 #include <fuse_lowlevel.h>
