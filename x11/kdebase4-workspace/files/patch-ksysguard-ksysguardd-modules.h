--- ksysguard/ksysguardd/modules.h.orig	Sat May  4 16:49:24 2002
+++ ksysguard/ksysguardd/modules.h	Sat May  4 16:52:34 2002
@@ -45,7 +45,9 @@
 #include "CPU.h"
 #include "Memory.h"
 #include "ProcessList.h"
+#ifdef __i386__
 #include "apm.h"
+#endif
 #include "diskstat.h"
 #include "loadavg.h"
 #include "logfile.h"
@@ -104,13 +106,19 @@
 	{ "CpuInfo", initCpuInfo, exitCpuInfo, updateCpuInfo, NULLVVFUNC },
 	{ "Memory", initMemory, exitMemory, updateMemory, NULLVVFUNC },
 	{ "ProcessList", initProcessList, exitProcessList, updateProcessList, NULLVVFUNC },
+#ifdef __i386__
 	{ "Apm", initApm, exitApm, updateApm, NULLVVFUNC },
+#endif
 	{ "DiskStat", initDiskStat, exitDiskStat, updateDiskStat, checkDiskStat },
 	{ "LoadAvg", initLoadAvg, exitLoadAvg, updateLoadAvg, NULLVVFUNC },
 	{ "LogFile", initLogFile, exitLogFile, NULLVVFUNC, NULLVVFUNC },
 	{ "NetDev", initNetDev, exitNetDev, updateNetDev, checkNetDev },
 };
+#ifdef __i386__
 #define NUM_MODULES 8
+#else
+#define NUM_MODULES 7
+#endif
 #endif /* OSTYPE_FreeBSD */
 
 #ifdef OSTYPE_Solaris
