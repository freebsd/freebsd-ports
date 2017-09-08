Include '<errno.h>' as 'errno' is used.

--- src/helper/UserSession.cpp.orig	2016-07-06 14:00:10 UTC
+++ src/helper/UserSession.cpp
@@ -25,6 +25,7 @@
 
 #include <sys/types.h>
 #include <sys/ioctl.h>
+#include <errno.h>
 #include <unistd.h>
 #include <pwd.h>
 #include <grp.h>
