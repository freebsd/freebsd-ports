--- vtest/vtest_renderer.c.orig	2020-05-16 19:25:05 UTC
+++ vtest/vtest_renderer.c
@@ -35,7 +35,9 @@
 #include <sys/uio.h>
 #include <sys/socket.h>
 #include <sys/mman.h>
+#include <sys/stat.h>
 
+
 #include "vtest.h"
 #include "vtest_shm.h"
 #include "vtest_protocol.h"
@@ -158,7 +160,7 @@ int vtest_block_read(struct vtest_input *input, void *
    if (getenv("VTEST_SAVE")) {
       if (savefd == -1) {
          savefd = open(getenv("VTEST_SAVE"),
-                       O_CLOEXEC|O_CREAT|O_WRONLY|O_TRUNC|O_DSYNC, S_IRUSR|S_IWUSR);
+                       O_CLOEXEC|O_CREAT|O_WRONLY|O_TRUNC|O_SYNC, S_IRUSR|S_IWUSR);
          if (savefd == -1) {
             perror("error opening save file");
             exit(1);
