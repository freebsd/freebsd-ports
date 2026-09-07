--- mangobar.c.orig	2026-09-01 09:23:05 UTC
+++ mangobar.c
@@ -10,7 +10,11 @@
 #include <fcft/fcft.h>
 #include <fcntl.h>
 #include <locale.h>
+#ifdef __FreeBSD__
+#include <dev/evdev/input-event-codes.h>
+#else
 #include <linux/input-event-codes.h>
+#endif
 #include <libudev.h>
 #include <pixman.h>
 #include <poll.h>
