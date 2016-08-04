--- frontend/common/src/ScreenLockCommandline.cc.orig	2016-05-11 16:14:20 UTC
+++ frontend/common/src/ScreenLockCommandline.cc
@@ -27,6 +27,8 @@
 #include <glib.h>
 #endif
 
+#include <sys/wait.h>
+
 #include "ScreenLockCommandline.hh"
 #include "debug.hh"
 
