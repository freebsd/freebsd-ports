--- src/stdxinc.cc.orig	2019-07-01 08:18:45 UTC
+++ src/stdxinc.cc
@@ -7,6 +7,7 @@
  ****************************************************************************/
 
 #include "stdxinc.h"
+#include <cstring>
 #define XC_pirate 88
 
 char *Get_Display_Name(int *pargc, char **argv) 
