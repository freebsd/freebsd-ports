--- src/common.cpp.orig	2018-04-13 19:33:54 UTC
+++ src/common.cpp
@@ -24,7 +24,7 @@
 #if !defined(_WIN32)
 #  include <locale.h>
 #  include <signal.h>
-#  include <sys/dir.h>
+#  include <dirent.h>
 #endif
 
 NAMESPACE_BEGIN(nanogui)
