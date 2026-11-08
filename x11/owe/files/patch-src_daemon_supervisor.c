--- src/daemon/supervisor.c.orig	2026-09-29 13:36:54 UTC
+++ src/daemon/supervisor.c
@@ -10,6 +10,10 @@
 #include <string.h>
 #include <sys/wait.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
 
 #include "common_ipc.h"
 #include "log.h"
@@ -62,6 +66,21 @@ static int render_socket_ready(const char *path) {
     return 1;
 }
 
+/* Absolute path of the running executable, like readlink(2) on /proc/self/exe. */
+static ssize_t self_exe_path(char *buf, size_t len) {
+#ifdef __FreeBSD__
+    int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+    size_t size = len;
+    if (sysctl(mib, 4, buf, &size, NULL, 0) != 0 || size == 0 || buf[0] == '\0') {
+        return -1;
+    }
+    buf[len - 1] = '\0';
+    return (ssize_t)strlen(buf);
+#else
+    return readlink("/proc/self/exe", buf, len);
+#endif
+}
+
 static int spawn_render(struct owed_supervisor *s) {
     char self[PATH_MAX];
     char dir[PATH_MAX * 2];
@@ -69,7 +88,7 @@ static int spawn_render(struct owed_supervisor *s) {
     char *argv[] = { "owe-render", "--socket", s->socket_path, NULL };
     ssize_t n;
     char *slash;
-    n = readlink("/proc/self/exe", self, sizeof(self) - 1);
+    n = self_exe_path(self, sizeof(self) - 1);
     if (n > 0) {
         self[n] = '\0';
         snprintf(dir, sizeof(dir), "%s", self);
