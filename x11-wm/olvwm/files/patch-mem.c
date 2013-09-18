--- mem.c.orig	Thu Jan 13 15:36:08 1994
+++ mem.c	Mon Oct 19 13:47:49 1998
@@ -18,7 +18,12 @@
 
 
 #include <sys/types.h>
+#include <sys/param.h>
+#ifndef __STDC__
 #include <malloc.h>
+#else
+#include <stdlib.h>
+#endif
 #include <memory.h>
 #include <stdio.h>
 
