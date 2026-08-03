--- src/common/VirtualTerminal.cpp.orig	2025-01-31 09:57:01 UTC
+++ src/common/VirtualTerminal.cpp
@@ -29,6 +29,7 @@
 #include <signal.h>
 #ifdef __FreeBSD__
 #include <sys/consio.h>
+#include <termios.h>
 #else
 #include <linux/vt.h>
 #include <linux/kd.h>
