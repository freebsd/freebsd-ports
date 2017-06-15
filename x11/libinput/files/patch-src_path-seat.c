--- src/path-seat.c.orig	2017-01-19 05:27:32 UTC
+++ src/path-seat.c
@@ -23,10 +23,11 @@
 
 #include "config.h"
 
+#include <sys/stat.h>
+
 #include <errno.h>
 #include <fcntl.h>
 #include <string.h>
-#include <sys/stat.h>
 #include <libudev.h>
 
 #include "path-seat.h"
