--- VkTrace.C.orig	Thu Jul 11 08:46:58 2002
+++ VkTrace.C	Wed Jul 23 03:22:53 2003
@@ -28,8 +28,13 @@
 #include <stdio.h>
 #include <time.h>
 #include <string.h>
+#include <stdarg.h>
 
 #include <Vk/VkTrace.h>
+#include <fstream>
+
+using std::ofstream;
+using std::endl;
 
 ofstream* vkTraceOut = 0;
 
