--- xnodecor.c.orig	Wed Jan 13 01:55:20 1999
+++ xnodecor.c	Mon Nov 11 23:15:42 2002
@@ -39,7 +39,8 @@
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
- 
+#include <unistd.h>
+
 #define WAIT_DEFAULT	0
 #define WAIT_TIMEOUT	15
 #define VERBOSE_DEFAULT	0
