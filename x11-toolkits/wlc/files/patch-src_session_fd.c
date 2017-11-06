--- src/session/fd.c.orig	2016-08-19 13:28:50 UTC
+++ src/session/fd.c
@@ -10,7 +10,9 @@
 #include <sys/select.h>
 #include <sys/socket.h>
 #include <sys/types.h>
+#if !defined(__FreeBSD__)
 #include <linux/major.h>
+#endif
 #include <xf86drm.h>
 #include "internal.h"
 #include "macros.h"
@@ -135,7 +137,7 @@ recv_fd(int sock, int *out_fd, void *out
       return read;
 
    if (message.msg_controllen == 0)
-   	  return read;
+      return read;
 
    if (!(cmsg = CMSG_FIRSTHDR(&message)))
       return read;
@@ -171,6 +173,7 @@ fd_open(const char *path, int flags, enu
    }
 
    /* we will only open allowed paths */
+#if !defined(__FreeBSD__)
 #define FILTER(x, m) { x, (sizeof(x) > 32 ? 32 : sizeof(x)) - 1, m }
    static struct {
       const char *base;
@@ -186,14 +189,15 @@ fd_open(const char *path, int flags, enu
       wlc_log(WLC_LOG_WARN, "Denying open from: %s", path);
       return -1;
    }
+#endif
 
    struct stat st;
    if (stat(path, &st) < 0)
-	  return -1;
+      return -1;
 
-#ifdef __linux__
+#if !defined(__FreeBSD__)
    if (major(st.st_rdev) != allow[type].major)
-   	  return -1;
+      return -1;
 #endif
 
    int fd;
