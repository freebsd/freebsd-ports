--- source/rofi.c.orig	2022-08-19 22:37:43.000000000 +0200
+++ source/rofi.c	2024-01-24 09:25:58.146073000 +0100
@@ -30,6 +30,7 @@
 #define G_LOG_DOMAIN "Rofi"
 
 #include "config.h"
+#include <sys/stat.h>
 #include <errno.h>
 #include <gmodule.h>
 #include <locale.h>
