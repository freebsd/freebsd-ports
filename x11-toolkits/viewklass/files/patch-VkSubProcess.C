--- ./VkSubProcess.C.orig	Wed Jul 23 02:39:49 2003
+++ ./VkSubProcess.C	Wed Jul 23 02:40:21 2003
@@ -40,6 +40,10 @@
 #include <signal.h>
 #include <stdio.h>
 #include <unistd.h> // for exec*
+#include <iostream>
+
+using std::cerr;
+using std::endl;
 
 VkSubProcess::VkSubProcess(char *prog,
 						   VkNameList *given,
