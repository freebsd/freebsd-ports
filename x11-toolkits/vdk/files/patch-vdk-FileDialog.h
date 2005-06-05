--- vdk/FileDialog.h.orig	Sun Jun  5 20:03:15 2005
+++ vdk/FileDialog.h	Sun Jun  5 20:03:31 2005
@@ -35,7 +35,9 @@
 #ifndef _USE_FNMATCH
 # include <regex.h>
 #else
+extern "C" {
 # include <fnmatch.h>
+}
 #endif
 
 #include <dirent.h>
