--- src/evdev.c.orig	2017-01-19 21:36:55 UTC
+++ src/evdev.c
@@ -25,6 +25,8 @@
 
 #include "config.h"
 
+#include <sys/stat.h>
+
 #include <errno.h>
 #include <stdbool.h>
 #include <stdlib.h>
