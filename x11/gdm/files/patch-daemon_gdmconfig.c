--- daemon/gdmconfig.c.orig	Thu Jan  5 16:57:06 2006
+++ daemon/gdmconfig.c	Thu Jan  5 16:57:44 2006
@@ -39,6 +39,7 @@
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/resource.h>
 #include <signal.h>
 #include <pwd.h>
 #include <grp.h>
