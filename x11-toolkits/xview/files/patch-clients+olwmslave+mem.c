--- ./clients/olwmslave/mem.c.orig	Tue Jun 29 07:12:12 1993
+++ ./clients/olwmslave/mem.c	Sat Apr  1 18:26:06 2000
@@ -16,7 +16,8 @@ static	char	sccsid[] = "@(#) mem.c 26.1 
  *
  */
 
-#include <malloc.h>
+#include <sys/param.h>
+#include <stdlib.h>
 #include <memory.h>
 #include <stdio.h>
 #include <sys/types.h>
