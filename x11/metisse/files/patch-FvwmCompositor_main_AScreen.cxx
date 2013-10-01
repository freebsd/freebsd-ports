--- FvwmCompositor/main/AScreen.cxx.orig	2008-11-25 10:22:45.000000000 +0000
+++ FvwmCompositor/main/AScreen.cxx
@@ -10,6 +10,7 @@
  *
  */
 
+#include <unistd.h>
 #ifdef HAVE_CONFIG_H
 #include "config-not-xserver.h"
 #endif
