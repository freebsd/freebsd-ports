--- ./VkWindow.C.orig	Wed Jul 23 02:21:06 2003
+++ ./VkWindow.C	Wed Jul 23 02:21:39 2003
@@ -42,6 +42,10 @@
 #include <Vk/VkWindow.h>
 #include <iostream.h>
 
+using std::cerr;
+using std::endl;
+using std::exception;
+
 VkWindow::VkWindow(const char* name,
 				   ArgList args,
 				   Cardinal argCount)
