--- src/daemon/main.c.orig	2026-09-29 13:36:53 UTC
+++ src/daemon/main.c
@@ -14,6 +14,11 @@
 #include <sys/stat.h>
 #include <sys/wait.h>
 #include <time.h>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#endif
 #include <unistd.h>
 
 #include "yyjson.h"
@@ -713,8 +718,64 @@ static void on_sigchld(int sig) {
     errno = saved_errno;
 }
 
+static bool blocklist_matches(const char *comm) {
+    owed_app_t *app = &g_app;
+    int i;
+    for (i = 0; i < app->config.blocklist_count; i++) {
+        if (strcmp(comm, app->config.blocklist[i]) == 0) {
+            OWE_DEBUG("blocklist match: %s", comm);
+            return true;
+        }
+    }
+    return false;
+}
+
+#ifdef __FreeBSD__
+/* FreeBSD has no /proc/<pid>/comm; walk the process table via sysctl. */
 static bool blocklist_active(void) {
     owed_app_t *app = &g_app;
+    int mib[3] = { CTL_KERN, KERN_PROC, KERN_PROC_PROC };
+    struct kinfo_proc *procs = NULL;
+    size_t size = 0;
+    size_t count, i;
+    bool found = false;
+    int attempt;
+
+    if (app->config.blocklist_count <= 0) {
+        return false;
+    }
+    for (attempt = 0; attempt < 4; attempt++) {
+        if (sysctl(mib, 3, NULL, &size, NULL, 0) != 0) {
+            return false;
+        }
+        size += size / 8;
+        free(procs);
+        procs = malloc(size);
+        if (!procs) {
+            return false;
+        }
+        if (sysctl(mib, 3, procs, &size, NULL, 0) == 0) {
+            break;
+        }
+        if (errno != ENOMEM) {
+            free(procs);
+            return false;
+        }
+    }
+    if (attempt == 4) {
+        free(procs);
+        return false;
+    }
+    count = size / sizeof(*procs);
+    for (i = 0; i < count && !found; i++) {
+        found = blocklist_matches(procs[i].ki_comm);
+    }
+    free(procs);
+    return found;
+}
+#else
+static bool blocklist_active(void) {
+    owed_app_t *app = &g_app;
     DIR *dir;
     struct dirent *ent;
     bool found = false;
@@ -730,7 +791,6 @@ static bool blocklist_active(void) {
         char path[320];
         char comm[128];
         FILE *f;
-        int i;
 
         if (ent->d_name[0] < '0' || ent->d_name[0] > '9') {
             continue;
@@ -746,17 +806,12 @@ static bool blocklist_active(void) {
         }
         fclose(f);
         comm[strcspn(comm, "\n")] = '\0';
-        for (i = 0; i < app->config.blocklist_count; i++) {
-            if (strcmp(comm, app->config.blocklist[i]) == 0) {
-                OWE_DEBUG("blocklist match: %s", comm);
-                found = true;
-                break;
-            }
-        }
+        found = blocklist_matches(comm);
     }
     closedir(dir);
     return found;
 }
+#endif
 
 static bool every_ms(int64_t *last_ms, int interval_ms) {
     struct timespec now;
