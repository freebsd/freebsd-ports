--- arch/debug.hh.orig	Sun Jul 13 10:04:38 2003
+++ arch/debug.hh	Sun Jul 13 10:04:55 2003
@@ -21,6 +21,8 @@
 #ifndef DEBUG_HH
 #define DEBUG_HH
 
+#include <assert.h>
+
 #ifndef CWDEBUG
 
 #define AllocTag1(p)
