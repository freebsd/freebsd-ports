--- kcms/touchpad/src/backends/x11/synapticstouchpad.cpp.orig	2016-03-29 09:10:43 UTC
+++ kcms/touchpad/src/backends/x11/synapticstouchpad.cpp
@@ -50,6 +50,7 @@
 
 #include "synapticstouchpad.h"
 
+#include <cmath>
 #include <stddef.h>
 #include <limits.h>
 #include <xorg/synaptics-properties.h>
