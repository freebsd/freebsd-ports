--- src/mango.c.orig	2026-05-29 13:04:35 UTC
+++ src/mango.c
@@ -7,7 +7,11 @@
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
