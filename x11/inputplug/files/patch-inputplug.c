--- inputplug.c.orig	2020-10-10 11:36:14 UTC
+++ inputplug.c
@@ -3,6 +3,9 @@
 #include <assert.h>
 #include <unistd.h>
 #include <errno.h>
+#if __FreeBSD__
+#include <signal.h>
+#endif
 #include <stdio.h>
 #include <stdbool.h>
 #include <stdint.h>
