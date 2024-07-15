--- lib/mystrcasecmp.c.orig	1996-08-21 14:23:34 UTC
+++ lib/mystrcasecmp.c
@@ -1,6 +1,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
+#include <string.h>
 
 int mystrcasecmp(char *s1,char *s2)
 {
