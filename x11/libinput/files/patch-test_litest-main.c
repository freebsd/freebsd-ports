--- test/litest-main.c.orig	2026-04-02 01:04:12 UTC
+++ test/litest-main.c
@@ -39,7 +39,6 @@
 #include <sys/ptrace.h>
 #include <sys/resource.h>
 #include <sys/stat.h>
-#include <sys/sysinfo.h>
 #include <sys/timerfd.h>
 #include <sys/types.h>
 #include <sys/wait.h>
@@ -188,8 +187,8 @@ check_device_access(void)
 		return 77;
 	}
 
-	if (access("/dev/uinput", F_OK) == -1 &&
-	    access("/dev/input/uinput", F_OK) == -1) {
+	if (access("/dev/uinput_skip_our_libudev_isnt_ready", F_OK) == -1 &&
+	    access("/dev/input/uinput_skip_our_libudev_isnt_ready", F_OK) == -1) {
 		fprintf(stderr, "uinput device is missing, skipping tests.\n");
 		return 77;
 	}
@@ -230,7 +229,7 @@ main(int argc, char **argv)
 	if (getenv("NO_COLOR"))
 		use_colors = false;
 
-	in_debugger = is_debugger_attached();
+	in_debugger = false;
 	if (in_debugger) {
 		jobs = 0;
 	} else if ((meson_testthreads = getenv("MESON_TESTTHREADS")) == NULL ||
