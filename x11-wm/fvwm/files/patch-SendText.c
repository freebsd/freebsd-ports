--- ./libs/SendText.c.orig	1994-09-13 18:53:12.000000000 +0000
+++ ./libs/SendText.c	2009-03-11 09:42:49.000000000 +0000
@@ -1,5 +1,7 @@
 #include <stdio.h>
 #include <ctype.h>
+#include <string.h>
+
 /************************************************************************
  *
  * Sends arbitrary text to fvwm
