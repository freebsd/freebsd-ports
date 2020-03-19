--- c3270/screen.c.orig	2018-02-10 22:07:45 UTC
+++ c3270/screen.c
@@ -31,6 +31,7 @@
  *		Screen drawing
  */
 
+#include <wctype.h>
 #include "globals.h"
 #include <signal.h>
 #include "appres.h"
