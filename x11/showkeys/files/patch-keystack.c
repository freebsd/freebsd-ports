--- keystack.c.orig	2020-03-24 16:28:07 UTC
+++ keystack.c
@@ -11,6 +11,7 @@
 #include <stdlib.h>
 #include <string.h>
 
+#include "config.h"
 #include "keystack.h"
 
 static void
