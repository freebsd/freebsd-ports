--- src/metadata.c.orig	2025-06-18 00:29:08 UTC
+++ src/metadata.c
@@ -25,6 +25,7 @@
  *          David Reveman <davidr@novell.com>
  */
 
+#include <stdlib.h>
 #include <string.h>
 #include <libxml/tree.h>
 #include <libxml/xpath.h>
