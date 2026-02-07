--- src/vt.c.orig	2019-08-04 22:29:55 UTC
+++ src/vt.c
@@ -16,6 +16,9 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
+#ifdef __FreeBSD__
+#include <sys/consio.h>
+#endif
 #ifdef __linux__
 #include <linux/vt.h>
 #endif
@@ -23,31 +26,56 @@
 #include "vt.h"
 #include "configuration.h"
 
+#if defined(__FreeBSD__)
+#define CONSOLE "/dev/console"
+#else
+#define CONSOLE "/dev/tty0"
+#endif
+
 static GList *used_vts = NULL;
 
 static gint
 open_tty (void)
 {
-    int fd = g_open ("/dev/tty0", O_RDONLY | O_NOCTTY, 0);
+    int fd = g_open (CONSOLE, O_RDONLY | O_NOCTTY, 0);
     if (fd < 0)
-        g_warning ("Error opening /dev/tty0: %s", strerror (errno));
+        g_warning ("Error opening " CONSOLE ": %s", strerror (errno));
     return fd;
 }
 
 gboolean
 vt_can_multi_seat (void)
 {
+#if defined(__linux__)
     /* Quick check to see if we can multi seat.  This is intentionally the
        same check logind does, just without actually reading from the files.
        Existence will prove whether we have CONFIG_VT built into the kernel. */
     return access ("/dev/tty0", F_OK) == 0 &&
            access ("/sys/class/tty/tty0/active", F_OK) == 0;
+#else
+    return FALSE;
+#endif
 }
 
 gint
 vt_get_active (void)
 {
-#ifdef __linux__
+#if defined(__FreeBSD__)
+    int active, res;
+    int tty_fd = open_tty ();
+
+    if (tty_fd >= 0)
+    {
+        res = ioctl (tty_fd, VT_GETACTIVE, &active);
+        close (tty_fd);
+        if (res == 0)
+            return active;
+
+        g_warning ("Error using VT_GETACTIVE on " CONSOLE ": %s", strerror (errno));
+    }
+
+    return -1;
+#elif defined(__linux__)
     /* Pretend always active */
     if (getuid () != 0)
         return 1;
@@ -73,7 +101,7 @@ vt_set_active (gint number)
 void
 vt_set_active (gint number)
 {
-#ifdef __linux__
+#if defined(__FreeBSD__) || defined(__linux__)
     g_debug ("Activating VT %d", number);
 
     /* Pretend always active */
@@ -86,7 +114,7 @@ vt_set_active (gint number)
         int n = number;
         if (ioctl (tty_fd, VT_ACTIVATE, n) < 0)
         {
-            g_warning ("Error using VT_ACTIVATE %d on /dev/tty0: %s", n, strerror (errno));
+            g_warning ("Error using VT_ACTIVATE %d on " CONSOLE ": %s", n, strerror (errno));
             close (tty_fd);
             return;
         }
@@ -101,7 +129,7 @@ vt_set_active (gint number)
             {
                 if (errno == EINTR)
                     continue;
-                g_warning ("Error using VT_WAITACTIVE %d on /dev/tty0: %s", n, strerror (errno));
+                g_warning ("Error using VT_WAITACTIVE %d on " CONSOLE ": %s", n, strerror (errno));
             }
             break;
         }
