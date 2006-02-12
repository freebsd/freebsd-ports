--- ksmserver/legacy.cpp.orig	Sun Feb 12 16:47:39 2006
+++ ksmserver/legacy.cpp	Sun Feb 12 16:48:55 2006
@@ -36,6 +36,10 @@
 
 #include "server.h"
 
+#ifdef HAVE_SYS_TIME_H
+#include <sys/time.h>
+#endif
+
 #include <unistd.h>
 
 #include <qtimer.h>
