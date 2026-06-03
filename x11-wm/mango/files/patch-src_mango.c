--- src/mango.c.orig	2025-12-03 10:15:56 UTC
+++ src/mango.c
@@ -6,7 +6,11 @@
 #include <getopt.h>
 #include <libinput.h>
 #include <limits.h>
+#ifdef __FreeBSD__
+#include <dev/evdev/input-event-codes.h>
+#else
 #include <linux/input-event-codes.h>
+#endif
 #include <scenefx/render/fx_renderer/fx_renderer.h>
 #include <scenefx/types/fx/blur_data.h>
 #include <scenefx/types/fx/clipped_region.h>
