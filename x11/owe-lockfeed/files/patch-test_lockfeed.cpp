--- test/lockfeed.cpp.orig	2026-09-29 13:36:18 UTC
+++ test/lockfeed.cpp
@@ -57,12 +57,12 @@ int descriptorCount(int fd) {
     int count = 0;
     struct stat target;
     if (fstat(fd, &target) != 0) return -1;
-    const QDir directory(QStringLiteral("/proc/self/fd"));
-    for (const QString &entry : directory.entryList(QDir::AllEntries | QDir::NoDotAndDotDot)) {
-        bool numeric = false;
-        const int candidate = entry.toInt(&numeric);
+    // Probe the descriptor table directly rather than listing /proc/self/fd,
+    // which only exists on Linux.
+    const int limit = getdtablesize();
+    for (int candidate = 0; candidate < limit; candidate++) {
         struct stat st;
-        if (numeric && fstat(candidate, &st) == 0 && st.st_dev == target.st_dev && st.st_ino == target.st_ino) {
+        if (fstat(candidate, &st) == 0 && st.st_dev == target.st_dev && st.st_ino == target.st_ino) {
             count++;
         }
     }
