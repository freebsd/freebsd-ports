--- src/libinput.h.orig	2017-01-19 05:27:32 UTC
+++ src/libinput.h
@@ -29,6 +29,7 @@
 extern "C" {
 #endif
 
+#include <stdarg.h>
 #include <stdlib.h>
 #include <stdint.h>
 #include <libudev.h>
