--- ./libs/mystrcasecmp.c.orig	1994-09-14 15:55:20.000000000 +0000
+++ ./libs/mystrcasecmp.c	2009-03-11 09:42:49.000000000 +0000
@@ -1,6 +1,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
+#include <string.h>
 
 int mystrcasecmp(char *s1,char *s2)
 {
