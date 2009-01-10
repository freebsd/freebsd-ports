--- common/gdm-common.c.orig	2007-12-23 10:29:20.000000000 +0100
+++ common/gdm-common.c	2007-12-23 10:29:34.000000000 +0100
@@ -33,6 +33,10 @@
 
 #include "gdm-common.h"
 
+#ifndef ENODATA
+#define ENODATA EAGAIN
+#endif
+
 void
 gdm_set_fatal_warnings_if_unstable (void)
 {
