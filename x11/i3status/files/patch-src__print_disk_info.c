--- ./src/print_disk_info.c.orig	2011-07-21 23:11:48.000000000 +0200
+++ ./src/print_disk_info.c	2011-12-08 15:47:21.000000000 +0100
@@ -6,6 +6,11 @@
 #include <stdint.h>
 #include <sys/statvfs.h>
 #include <sys/types.h>
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#include <sys/param.h>
+#include <sys/mount.h>
+#endif
+
 
 #include "i3status.h"
 
@@ -39,10 +44,18 @@
  */
 void print_disk_info(const char *path, const char *format) {
         const char *walk;
+
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+        struct statfs buf;
+
+        if (statfs(path, &buf) == -1)
+                return;
+#else
         struct statvfs buf;
 
         if (statvfs(path, &buf) == -1)
                 return;
+#endif
 
         for (walk = format; *walk != '\0'; walk++) {
                 if (*walk != '%') {
@@ -63,6 +76,7 @@
                 if (BEGINS_WITH(walk+1, "total")) {
                         print_bytes_human((uint64_t)buf.f_bsize * (uint64_t)buf.f_blocks);
                         walk += strlen("total");
+
                 }
 
                 if (BEGINS_WITH(walk+1, "avail")) {
