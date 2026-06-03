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
@@ -217,6 +218,19 @@ out:
                 // set graphics mode to prevent flickering
                 if (ioctl(fd, KDSETMODE, KD_GRAPHICS) < 0)
                     qWarning("Failed to set graphics mode for VT %d: %s", vt, strerror(errno));
+
+#ifdef __FreeBSD__
+                struct termios tios;
+
+                if (tcgetattr(fd, &tios) != 0) {
+                    qFatal("Failed to get term attrs for VT %d: %s", vt, strerror(errno));
+                } else {
+                cfmakeraw(&tios);
+                    if (tcsetattr(fd, TCSAFLUSH, &tios) != 0) {
+                        qWarning("Failed to set term attrs for VT %d: %s", vt, strerror(errno));
+                    }
+                }
+#endif
 
                 // it's possible that the current VT was left in a broken
                 // combination of states (KD_GRAPHICS with VT_AUTO) that we
