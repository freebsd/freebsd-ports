--- ./src/cfgparse.l.orig	2011-01-19 21:26:37.000000000 +0100
+++ ./src/cfgparse.l	2011-01-22 20:43:13.000000000 +0100
@@ -10,6 +10,7 @@
  */
 #include <stdio.h>
 #include <string.h>
+#include <stdint.h> /* Defines uint32_t, required by cfgparse.tab.h */
 #include "cfgparse.tab.h"
 #include <xcb/xcb.h>
 
