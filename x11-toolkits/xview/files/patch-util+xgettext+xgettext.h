--- util/xgettext/xgettext.h.orig	Tue Jun 29 00:14:13 1993
+++ util/xgettext/xgettext.h	Thu Oct 16 14:32:50 2003
@@ -8,13 +8,14 @@
 #include <signal.h>
 #include <sys/types.h>
 
-#ifndef SVR4
+#include <sys/param.h>
+
+#if !(defined(BSD4_4) || defined(SVR4))
 #include <sys/dir.h>
 #else
 #include <dirent.h>
-#endif SVR4
+#endif /* SVR4 */
 
-#include <sys/param.h>
 #include <sys/stat.h>
 
 #define DOMAIN_TOKEN    "domain"
