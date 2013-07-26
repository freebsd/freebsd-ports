--- Common/FileSystemInfo/FileSystemInfo.h.orig	2012-02-22 22:28:12.000000000 +0400
+++ Common/FileSystemInfo/FileSystemInfo.h	2012-07-16 22:55:36.977549896 +0400
@@ -14,6 +14,7 @@
 #else
 #include <unistd.h>
 #include <dirent.h>
+#include <sys/syslimits.h>
 #endif
 
 #include <string>
