--- src/core/util.c.orig	2008-02-27 05:42:51.000000000 +0100
+++ src/core/util.c	2008-03-21 21:16:14.000000000 +0100
@@ -23,7 +23,7 @@
  */
 
 #define _GNU_SOURCE
-#define _POSIX_C_SOURCE /* for fdopen() */
+#define _POSIX_C_SOURCE 1 /* for fdopen() */
 
 #include <config.h>
 #include "util.h"
