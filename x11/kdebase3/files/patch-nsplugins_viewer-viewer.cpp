--- nsplugins/viewer/viewer.cpp.orig	Mon Dec 19 00:30:44 2005
+++ nsplugins/viewer/viewer.cpp	Mon Dec 19 00:43:33 2005
@@ -54,7 +54,14 @@
 #include "qxteventloop.h"
 #endif
 
+/**
+ *  Use RLIMIT_DATA on systems that don't define RLIMIT_AS,
+ *  such as FreeBSD 4.
+ */
 
+#ifndef RLIMIT_AS
+#define RLIMIT_AS RLIMIT_DATA
+#endif
 
 /**
  * The error handler catches all X errors, writes the error
