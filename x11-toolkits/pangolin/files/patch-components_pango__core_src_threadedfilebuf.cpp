- workaround for https://github.com/stevenlovegrove/Pangolin/issues/760

--- components/pango_core/src/threadedfilebuf.cpp.orig	2022-05-03 23:10:42 UTC
+++ components/pango_core/src/threadedfilebuf.cpp
@@ -32,6 +32,8 @@
 #include <cstring>
 #include <stdexcept>
 
+#include <sys/stat.h>
+
 #ifdef USE_POSIX_FILE_IO
 #include <unistd.h>
 #include <fcntl.h>
