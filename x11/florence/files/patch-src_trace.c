--- src/trace.c.orig	2010-11-28 14:59:13.000000000 +0000
+++ src/trace.c
@@ -22,9 +22,7 @@
 #include "trace.h"
 #include "system.h"
 #include <glib/gprintf.h>
-#include <glib/gutils.h>
-#include <glib/gslist.h>
-#include <glib/gstrfuncs.h>
+#include <glib.h>
 #include <stdio.h>
 #include <stdarg.h>
