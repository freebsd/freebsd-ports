--- src/window.cpp.orig	2025-06-27 19:43:51 UTC
+++ src/window.cpp
@@ -13,7 +13,24 @@
 #include <unistd.h>
 #include <wayland-client-protocol.h>
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/ucred.h>
+#include <sys/un.h>
+#include <sys/user.h>
+#include <libutil.h>
+#endif
+
 static pid_t pid_from_fd(const int fd) {
+#if defined(__FreeBSD__)
+    xucred cred{};
+    socklen_t len = sizeof(struct xucred);
+    if (getsockopt(fd, SOL_LOCAL, LOCAL_PEERCRED, &cred, &len) == -1) {
+        perror("getsockopt failed");
+        exit(1);
+    }
+    return cred.cr_pid;
+#else
     ucred cred{};
     socklen_t len = sizeof(struct ucred);
     if (getsockopt(fd, SOL_SOCKET, SO_PEERCRED, &cred, &len) == -1) {
@@ -21,9 +38,19 @@ static pid_t pid_from_fd(const int fd) {
         exit(1);
     }
     return cred.pid;
+#endif
 }
 
 static std::string process_name_from_pid(const pid_t pid) {
+#if defined(__FreeBSD__)
+    struct kinfo_proc *proc = kinfo_getproc(pid);
+
+    if (proc) {
+        std::string out = proc->ki_comm;
+        free(proc);
+        return out;
+    }
+#else
     const std::string procpath = QString::asprintf("/proc/%d/comm", pid).toStdString();
 
     std::ifstream infile(procpath);
@@ -38,7 +65,7 @@ static std::string process_name_from_pid(const pid_t p
         // running in a flatpak or a snap, most likely
         return "Unknown (Sandboxed)";
     }
-
+#endif
     return "Unknown";
 }
 
