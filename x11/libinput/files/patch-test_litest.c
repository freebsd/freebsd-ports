--- test/litest.c.orig	2026-04-02 01:04:12 UTC
+++ test/litest.c
@@ -39,7 +39,6 @@
 #include <sys/ptrace.h>
 #include <sys/resource.h>
 #include <sys/stat.h>
-#include <sys/sysinfo.h>
 #include <sys/timerfd.h>
 #include <sys/types.h>
 #include <sys/wait.h>
@@ -52,10 +51,10 @@
 #endif
 #ifdef __FreeBSD__
 #include <termios.h>
+#include <sys/kbio.h>
 #endif
 
 #include <libevdev/libevdev.h>
-#include <linux/kd.h>
 #include <valgrind/valgrind.h>
 
 #include "util-backtrace.h"
