--- src/notification/notification.c.orig	2011-04-21 11:51:08 UTC
+++ src/notification/notification.c
@@ -25,6 +25,7 @@
 #include <stdarg.h>
 #include <string.h>
 #include <unistd.h>
+#include "config.h"
 #include <compiz-core.h>
 
 #define NOTIFY_DISPLAY_OPTION_TIMEOUT   0
