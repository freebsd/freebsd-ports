--- ./clients/olwm/mem.c.orig	Tue Jun 29 07:11:45 1993
+++ ./clients/olwm/mem.c	Sat Apr  1 18:26:06 2000
@@ -14,8 +14,12 @@
  *
  */
 
-
+#include <sys/param.h>
+#ifdef __STDC__
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 #include <memory.h>
 #include <stdio.h>
 #include <sys/types.h>
