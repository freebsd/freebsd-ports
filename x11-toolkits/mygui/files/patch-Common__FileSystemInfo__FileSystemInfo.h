--- Common/FileSystemInfo/FileSystemInfo.h.orig	2014-04-22 06:12:03.384476313 +0400
+++ Common/FileSystemInfo/FileSystemInfo.h	2014-04-22 06:12:29.104475139 +0400
@@ -14,6 +14,7 @@
 #else
 #include <unistd.h>
 #include <dirent.h>
+#include <sys/syslimits.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
