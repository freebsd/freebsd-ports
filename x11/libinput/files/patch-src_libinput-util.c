--- src/libinput-util.c.orig	2017-01-17 04:53:51 UTC
+++ src/libinput-util.c
@@ -36,6 +36,9 @@
 #include <stdbool.h>
 #include <stdio.h>
 #include <stdlib.h>
+#ifdef __FreeBSD__
+#include <xlocale.h>
+#endif
 
 #include "libinput-util.h"
 #include "libinput-private.h"
