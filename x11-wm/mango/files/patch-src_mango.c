--- src/mango.c.orig	2026-08-27 06:44:37 UTC
+++ src/mango.c
@@ -9,7 +9,11 @@
 #include <getopt.h>
 #include <libinput.h>
 #include <limits.h>
+#ifdef __FreeBSD__
+#include <dev/evdev/input-event-codes.h>
+#else
 #include <linux/input-event-codes.h>
+#endif
 #include <math.h>
 #include <scenefx/render/fx_renderer/fx_renderer.h>
 #include <scenefx/types/fx/blur_data.h>
