--- src/main.c.orig	Mon Aug 25 02:53:00 2003
+++ src/main.c	Mon Aug 25 02:53:31 2003
@@ -25,6 +25,7 @@
 #include "zenity.h"
 #include <stdlib.h>
 #include <popt.h>
+#include <locale.h>
 #include <langinfo.h>
 
 typedef enum {
