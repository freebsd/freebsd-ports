--- lib/SendText.c.orig	1996-08-21 14:23:34 UTC
+++ lib/SendText.c
@@ -1,5 +1,7 @@
 #include <stdio.h>
 #include <ctype.h>
+#include <string.h>
+
 /************************************************************************
  *
  * Sends arbitrary text to afterstep 
