--- ../ksysguard/ksysguardd/FreeBSD/CPU.h.orig	2008-04-15 04:36:40.000000000 +0200
+++ ../ksysguard/ksysguardd/FreeBSD/CPU.h	2008-04-15 04:38:11.000000000 +0200
@@ -35,6 +35,8 @@
 void printCPUNiceInfo(const char* cmd);
 void printCPUSys(const char* cmd);
 void printCPUSysInfo(const char* cmd);
+void printCPUIntr(const char* cmd);
+void printCPUIntrInfo(const char* cmd);
 void printCPUIdle(const char* cmd);
 void printCPUIdleInfo(const char* cmd);
 void printCPUxUser(const char* cmd);
@@ -43,6 +45,8 @@
 void printCPUxNiceInfo(const char* cmd);
 void printCPUxSys(const char* cmd);
 void printCPUxSysInfo(const char* cmd);
+void printCPUxIntr(const char* cmd);
+void printCPUxIntrInfo(const char* cmd);
 void printCPUxIdle(const char* cmd);
 void printCPUxIdleInfo(const char* cmd);
 
