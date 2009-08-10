--- ./ksysguard/ksysguardd/FreeBSD/CPU.h.orig	2008-01-05 00:55:46.000000000 +0100
+++ ./ksysguard/ksysguardd/FreeBSD/CPU.h	2009-02-03 16:26:12.000000000 +0100
@@ -35,6 +35,10 @@
 void printCPUNiceInfo(const char* cmd);
 void printCPUSys(const char* cmd);
 void printCPUSysInfo(const char* cmd);
+void printCPUTotalLoad(const char* cmd);
+void printCPUTotalLoadInfo(const char* cmd);
+void printCPUIntr(const char* cmd);
+void printCPUIntrInfo(const char* cmd);
 void printCPUIdle(const char* cmd);
 void printCPUIdleInfo(const char* cmd);
 void printCPUxUser(const char* cmd);
@@ -43,6 +47,8 @@
 void printCPUxNiceInfo(const char* cmd);
 void printCPUxSys(const char* cmd);
 void printCPUxSysInfo(const char* cmd);
+void printCPUxIntr(const char* cmd);
+void printCPUxIntrInfo(const char* cmd);
 void printCPUxIdle(const char* cmd);
 void printCPUxIdleInfo(const char* cmd);
 
