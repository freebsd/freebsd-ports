--- arch/unix/Thread.cc.orig	Sun Jan  5 00:53:45 2003
+++ arch/unix/Thread.cc	Sat Jul  5 13:58:39 2003
@@ -20,6 +20,7 @@
 #include "config.h"
 #endif
 
+#include <time.h>
 #include "Thread.hh"
 
 void *
