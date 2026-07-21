--- src/managers/input/Eis.cpp.orig	2026-07-21 08:58:21 UTC
+++ src/managers/input/Eis.cpp
@@ -5,7 +5,12 @@
 #include "managers/SeatManager.hpp"
 #include "state/MonitorState.hpp"
 #include "output/Monitor.hpp"
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || \
+    defined(__DragonFly__)
+#include <stdlib.h>
+#else
 #include <alloca.h>
+#endif
 #include <cstdint>
 #include <hyprutils/os/FileDescriptor.hpp>
 #include <libeis.h>
