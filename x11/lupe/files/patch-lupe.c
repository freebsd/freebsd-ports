--- lupe.c.orig	1999-05-29 18:08:12.000000000 +0900
+++ lupe.c	2012-10-07 20:03:55.000000000 +0900
@@ -19,6 +19,10 @@
 #include "version.h"
 #include "timer.h"
 
+#ifdef HAVE_STDLIB_H
+#include <stdlib.h>
+#endif
+
 #ifdef HAVE_STRING_H
 #include <string.h>
 #else
@@ -339,7 +343,7 @@
   photo_delay *= 1000;		/* sec. to millisec. */
 }
 
-void main(argc, argv)
+int main(argc, argv)
      int argc;
      char **argv;
 {
