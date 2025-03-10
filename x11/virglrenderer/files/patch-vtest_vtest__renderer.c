--- vtest/vtest_renderer.c.orig	2024-01-08 20:00:59 UTC
+++ vtest/vtest_renderer.c
@@ -40,6 +40,7 @@
 #include <sys/uio.h>
 #include <sys/socket.h>
 #include <sys/mman.h>
+#include <sys/stat.h>
 #ifdef HAVE_EVENTFD_H
 #include <sys/eventfd.h>
 #endif
@@ -368,7 +369,7 @@ int vtest_block_read(struct vtest_input *input, void *
    if (getenv("VTEST_SAVE")) {
       if (savefd == -1) {
          savefd = open(getenv("VTEST_SAVE"),
-                       O_CLOEXEC|O_CREAT|O_WRONLY|O_TRUNC|O_DSYNC, S_IRUSR|S_IWUSR);
+                       O_CLOEXEC|O_CREAT|O_WRONLY|O_TRUNC|O_SYNC, S_IRUSR|S_IWUSR);
          if (savefd == -1) {
             perror("error opening save file");
             exit(1);
