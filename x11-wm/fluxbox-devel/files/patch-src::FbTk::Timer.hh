--- src/FbTk/Timer.hh.orig	Mon Jan 24 13:36:40 2005
+++ src/FbTk/Timer.hh	Mon Jan 24 14:00:05 2005
@@ -42,9 +42,9 @@
 #include <inttypes.h>
 #endif // HAVE_INTTYPES_H
 
+#include <sys/types.h>
 #include <sys/select.h>
 #include <sys/time.h>
-#include <sys/types.h>
 #include <unistd.h>
 
 namespace FbTk {
