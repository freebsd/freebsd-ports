--- src/xcb_util.c.orig	Wed Aug 23 02:46:44 2006
+++ src/xcb_util.c	Wed Aug 23 02:46:44 2006
@@ -39,6 +39,7 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
+#include <netinet/in.h> /* added by Ashish Shukla */
 
 #include "xcb.h"
 #include "xcbext.h"
