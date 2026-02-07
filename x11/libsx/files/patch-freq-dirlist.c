--- freq/dirlist.c.orig	Tue Feb 15 00:25:28 1994
+++ freq/dirlist.c	Wed Sep  3 14:11:59 1997
@@ -25,6 +25,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <sys/types.h>
 #include <dirent.h>
 #include <sys/param.h>
 #include <sys/stat.h>
