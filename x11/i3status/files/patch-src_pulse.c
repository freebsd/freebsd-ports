--- src/pulse.c.orig	2019-01-23 08:03:56 UTC
+++ src/pulse.c
@@ -1,3 +1,4 @@
+#ifndef __FreeBSD__
 // vim:ts=4:sw=4:expandtab
 #include <config.h>
 #include <string.h>
@@ -337,3 +338,4 @@ bool pulse_initialize(void) {
     }
     return true;
 }
+#endif
