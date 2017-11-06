--- src/session/tty.c.orig	2016-08-19 13:28:50 UTC
+++ src/session/tty.c
@@ -9,27 +9,18 @@
 #include "internal.h"
 #include "tty.h"
 
-#if defined(__linux__)
-#  define TTY_BASENAME "/dev/tty"
-#  define TTY_0        "/dev/tty0"
-#  include <linux/kd.h>
-#  include <linux/major.h>
-#  include <linux/vt.h>
-#elif defined(__FreeBSD__)
+#if defined(__FreeBSD__)
+#  include <termios.h>
 #  include <sys/consio.h>
 #  include <sys/kbio.h>
 #  define TTY_BASENAME    "/dev/ttyv"
 #  define TTY_0           "/dev/ttyv0"
-#  define TTY_MAJOR       0
-#  define VT_GETSTATE	  0x5603
-#  define VT_ACTIVATE	  0x5606
-#  define K_UNICODE       0x03
-#  define K_OFF           0x04
-struct vt_stat {
-    unsigned short v_active;    /* active vt */
-    unsigned short v_signal;	/* signal to send */
-    unsigned short v_state;	/* vt bitmask */
-};
+#else
+#  include <linux/kd.h>
+#  include <linux/major.h>
+#  include <linux/vt.h>
+#  define TTY_BASENAME "/dev/tty"
+#  define TTY_0        "/dev/tty0"
 #endif
 
 #ifndef KDSKBMUTE
@@ -100,22 +91,22 @@ open_tty(int vt)
 }
 
 static bool
-setup_tty(int fd, bool replace_vt)
+setup_tty(int fd, int vt, bool replace_vt)
 {
    if (fd < 0)
       return false;
 
+#if defined(__FreeBSD__)
+   wlc.vt = vt+1;
+#else
    struct stat st;
    if (fstat(fd, &st) == -1)
       die("Could not stat tty fd");
-
    wlc.vt = minor(st.st_rdev);
-
    if (major(st.st_rdev) != TTY_MAJOR || wlc.vt == 0)
       die("Not a valid vt");
+#endif
 
-/* FreeBSD's new vt is still missing some bits */
-#if defined(__linux__)
    if (!replace_vt) {
       int kd_mode;
       if (ioctl(fd, KDGETMODE, &kd_mode) == -1)
@@ -125,18 +116,20 @@ setup_tty(int fd, bool replace_vt)
          die("vt%d is already in graphics mode (%d). Is another display server running?", wlc.vt, kd_mode);
    }
 
+#if defined(__FreeBSD__)
+   ioctl(fd, VT_GETACTIVE, &wlc.old_state.vt);
+#else
    struct vt_stat state;
    if (ioctl(fd, VT_GETSTATE, &state) == -1)
       die("Could not get current vt");
-
    wlc.old_state.vt = state.v_active;
+#endif
 
    if (ioctl(fd, VT_ACTIVATE, wlc.vt) == -1)
       die("Could not activate vt%d", wlc.vt);
 
    if (ioctl(fd, VT_WAITACTIVE, wlc.vt) == -1)
       die("Could not wait for vt%d to become active", wlc.vt);
-#endif
 
    if (ioctl(fd, KDGKBMODE, &wlc.old_state.kb_mode) == -1)
       die("Could not get keyboard mode");
@@ -144,7 +137,19 @@ setup_tty(int fd, bool replace_vt)
    // vt will be restored from now on
    wlc.tty = fd;
 
-#if defined(__linux__)
+#if defined(__FreeBSD__)
+   if (ioctl(fd, KDSKBMODE, K_CODE) == -1) {
+      wlc_tty_terminate();
+      die("Could not set keyboard mode to K_CODE");
+   }
+   /* Put the tty into raw mode */
+   struct termios tios;
+   if (tcgetattr(fd, &tios))
+      die("Failed to get terminal attribute");
+   cfmakeraw(&tios);
+   if (tcsetattr(fd, TCSANOW, &tios))
+      die("Failed to set terminal attribute");
+#else
    if (ioctl(fd, KDSKBMUTE, 1) == -1 && ioctl(fd, KDSKBMODE, K_OFF) == -1) {
       wlc_tty_terminate();
       die("Could not set keyboard mode to K_OFF");
@@ -156,18 +161,19 @@ setup_tty(int fd, bool replace_vt)
       die("Could not set console mode to KD_GRAPHICS");
    }
 
-#if defined(__linux__)
    struct vt_mode mode = {
       .mode = VT_PROCESS,
       .relsig = SIGUSR1,
       .acqsig = SIGUSR2
    };
+#if defined(__FreeBSD__)
+   mode.frsig = SIGIO; /* not used, but has to be set anyway */
+#endif
 
    if (ioctl(fd, VT_SETMODE, &mode) == -1) {
       wlc_tty_terminate();
       die("Could not set vt%d mode", wlc.vt);
    }
-#endif
 
    return true;
 }
@@ -230,13 +236,19 @@ wlc_tty_terminate(void)
       // The ACTIVATE / WAITACTIVE may be potentially bad here.
       // However, we need to make sure the vt we initially opened is also active on cleanup.
       // We can't make sure this is synchronized due to unclean exits.
+
       if (ioctl(wlc.tty, VT_ACTIVATE, wlc.vt) != -1 && ioctl(wlc.tty, VT_WAITACTIVE, wlc.vt) != -1) {
          wlc_log(WLC_LOG_INFO, "Restoring vt %d (0x%lx) (fd %d)", wlc.vt, wlc.old_state.kb_mode, wlc.tty);
 
-         if (ioctl(wlc.tty, KDSKBMUTE, 0) == -1 &&
-             ioctl(wlc.tty, KDSKBMODE, wlc.old_state.kb_mode) == -1 &&
-             ioctl(wlc.tty, KDSKBMODE, K_UNICODE) == -1)
-            wlc_log(WLC_LOG_ERROR, "Failed to restore vt%d KDSKMODE", wlc.vt);
+#if defined(__FreeBSD__)
+         if (ioctl(wlc.tty, KDSKBMODE, wlc.old_state.kb_mode) == -1 &&
+             ioctl(wlc.tty, KDSKBMODE, K_XLATE) == -1)
+#else
+            if (ioctl(wlc.tty, KDSKBMUTE, 0) == -1 &&
+                ioctl(wlc.tty, KDSKBMODE, wlc.old_state.kb_mode) == -1 &&
+                ioctl(wlc.tty, KDSKBMODE, K_UNICODE) == -1)
+#endif
+               wlc_log(WLC_LOG_ERROR, "Failed to restore vt%d KDSKMODE", wlc.vt);
 
          if (ioctl(wlc.tty, KDSETMODE, KD_TEXT) == -1)
             wlc_log(WLC_LOG_ERROR, "Failed to restore vt%d mode to VT_AUTO", wlc.vt);
@@ -271,7 +283,7 @@ wlc_tty_init(int vt)
    if (!vt && !(vt = find_vt(getenv("XDG_VTNR"), &replace_vt)))
       die("Could not find vt");
 
-   if (!setup_tty(open_tty(vt), replace_vt))
+   if (!setup_tty(open_tty(vt), vt, replace_vt))
       die("Could not open tty with vt%d", vt);
 
    struct sigaction action = {
