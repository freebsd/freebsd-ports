--- src/notification/notification.c.orig	2014-06-02 19:46:42.417311366 +0100
+++ src/notification/notification.c	2014-06-02 19:46:50.130301442 +0100
@@ -25,6 +25,7 @@
 #include <stdarg.h>
 #include <string.h>
 #include <unistd.h>
+#include "config.h"
 #include <compiz-core.h>
 
 #define NOTIFY_DISPLAY_OPTION_TIMEOUT   0
