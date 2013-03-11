--- babl/babl-palette.c.orig	2012-05-04 12:44:48.000000000 +0200
+++ babl/babl-palette.c	2012-05-04 12:47:11.000000000 +0200
@@ -19,8 +19,11 @@
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
+#ifdef __linux__
 #include <values.h>
+#endif
 #include <assert.h>
+#include <sys/limits.h>
 #include "config.h"
 #include "babl-internal.h"
 #include "babl.h"
