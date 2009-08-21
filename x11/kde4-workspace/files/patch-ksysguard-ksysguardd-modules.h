--- ksysguard/ksysguardd/modules.h.orig	2009-08-20 20:02:06.000000000 +0200
+++ ksysguard/ksysguardd/modules.h	2009-08-20 21:53:11.000000000 +0200
@@ -59,6 +59,7 @@
 #include "Memory.h"
 #include "netdev.h"
 #include "ProcessList.h"
+#include "uptime.h"
 #endif /* OSTYPE_FreeBSD */
 
 #ifdef OSTYPE_Irix
@@ -144,6 +145,7 @@
   { "Memory", initMemory, exitMemory, updateMemory, NULLVVFUNC, 0, NULLTIME },
   { "NetDev", initNetDev, exitNetDev, updateNetDev, checkNetDev, 0, NULLTIME },
   { "ProcessList", initProcessList, exitProcessList, updateProcessList, NULLVVFUNC, 0, NULLTIME },
+  { "Uptime", initUptime, exitUptime, NULLIVFUNC, NULLVVFUNC, 0, NULLTIME },
 #endif /* OSTYPE_FreeBSD */
 
 #ifdef OSTYPE_Irix
