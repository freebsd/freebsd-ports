--- test/litest-runner.c.orig	2026-04-02 01:04:12 UTC
+++ test/litest-runner.c
@@ -26,7 +26,6 @@
 #include <errno.h>
 #include <inttypes.h>
 #include <sys/epoll.h>
-#include <sys/sysinfo.h>
 #include <sys/timerfd.h>
 #include <sys/wait.h>
 #ifdef HAVE_PIDFD_OPEN
