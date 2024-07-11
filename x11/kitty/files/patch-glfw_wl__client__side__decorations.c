--- glfw/wl_client_side_decorations.c.orig	1979-11-29 23:00:00 UTC
+++ glfw/wl_client_side_decorations.c
@@ -8,10 +8,23 @@
 #include "wl_client_side_decorations.h"
 
 #include "backend_utils.h"
+#include <sys/param.h>
+#include <sys/ucred.h>
 #include <sys/mman.h>
 #include <errno.h>
 #include <string.h>
 #include <stdlib.h>
+
+// Needed for the BTN_* definitions
+#ifdef __has_include
+#if __has_include(<linux/input.h>)
+#include <linux/input.h>
+#elif __has_include(<dev/evdev/input.h>)
+#include <dev/evdev/input.h>
+#endif
+#else
+#include <linux/input.h>
+#endif
 
 #define decs window->wl.decorations
 #define debug debug_rendering
