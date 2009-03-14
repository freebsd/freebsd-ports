--- ./modules/FvwmWinList/Mallocs.h.orig	1994-09-14 14:11:34.000000000 +0000
+++ ./modules/FvwmWinList/Mallocs.h	2009-03-11 09:42:48.000000000 +0000
@@ -18,8 +18,9 @@
  * own risk. Permission to use this program for any purpose is given,
  * as long as the copyright is kept intact. */
 
+#include "../../libs/fvwmlib.h"
+
 /* Function Prototypes */
-char *safemalloc(int length);
 char *saferealloc(char *ptr, int length);
 void sleep_a_little(int n);
 void CopyString(char **dest, char *source);
