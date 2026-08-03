This patch is twofold. First, it contains

https://github.com/sddm/sddm/pull/2210

then it prevents key combinations like Ctrl+C, Alt+F4, Ctrl+Alt+Del to go
directly into the VT causing unwanted effects. This part was copied from
bsd_init.c of xorg-server.

It does not restore the VT after messing it, but in practice the VT being used
for Wayland session starts from 10 and it isnt possible to switch into it via
normal ways.

--- src/helper/UserSession.cpp.orig	2025-01-31 09:57:01 UTC
+++ src/helper/UserSession.cpp
@@ -40,6 +40,9 @@
 #include <fcntl.h>
 #include <sched.h>
 #ifdef Q_OS_FREEBSD
+#include <sys/consio.h>
+#include <sys/kbio.h>
+#include <termios.h>
 #include <login_cap.h>
 #endif
 
@@ -191,6 +194,9 @@ namespace SDDM {
         const bool x11UserSession = sessionType == QLatin1String("x11") && sessionClass == QLatin1String("user");
         const bool waylandUserSession = sessionType == QLatin1String("wayland") && sessionClass == QLatin1String("user");
 
+        // when this is true we'll take control of the tty
+        bool takeControl = false;
+
         // When the display server is part of the session, we leak the VT into
         // the session as stdin so that it stays open without races
         if (hasDisplayServer || waylandUserSession) {
@@ -199,9 +205,6 @@ namespace SDDM {
             QString ttyString = VirtualTerminal::path(vtNumber);
             int vtFd = ::open(qPrintable(ttyString), O_RDWR | O_NOCTTY);
 
-            // when this is true we'll take control of the tty
-            bool takeControl = false;
-
             if (vtNumber > 0 && vtFd > 0) {
                 dup2(vtFd, STDIN_FILENO);
                 ::close(vtFd);
@@ -229,8 +232,38 @@ namespace SDDM {
             }
 
             if (vtNumber > 0)
-                VirtualTerminal::jumpToVt(vtNumber, x11UserSession);
+                VirtualTerminal::jumpToVt(vtNumber, true);
         }
+
+#ifdef __FreeBSD__
+        if (waylandUserSession) {
+            Q_ASSERT(takeControl);
+
+            struct termios tios;
+            int vtFd = STDIN_FILENO;
+
+            if (tcgetattr(vtFd, &tios) != 0) {
+                qWarning("Failed to get term attrs for VT 1: %s", strerror(errno));
+            }
+
+            /* disable special keys */
+            if (ioctl(vtFd, KDSKBMODE, K_RAW) < 0) {
+                qWarning("KDSKBMODE K_RAW failed (%s)", strerror(errno));
+            }
+
+            tios.c_iflag = IGNPAR | IGNBRK;
+            tios.c_oflag = 0;
+            tios.c_cflag = CREAD | CS8;
+            tios.c_lflag = 0;
+            tios.c_cc[VTIME] = 0;
+            tios.c_cc[VMIN] = 1;
+            cfsetispeed(&tios, 9600);
+            cfsetospeed(&tios, 9600);
+            if (tcsetattr(vtFd, TCSANOW, &tios) != 0) {
+                qWarning("tcsetattr TCSANOW failed (%s)", strerror(errno));
+            }
+        }
+#endif
 
 #ifdef Q_OS_LINUX
         // enter Linux namespaces
