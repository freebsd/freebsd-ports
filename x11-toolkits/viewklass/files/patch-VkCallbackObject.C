--- ./VkCallbackObject.C.orig	Wed Jul 23 02:08:26 2003
+++ ./VkCallbackObject.C	Wed Jul 23 02:09:04 2003
@@ -45,6 +45,9 @@
 #include <Vk/VkCallbackObject.h>
 #include <Vk/VkCallbackList.h>
 
+using std::cerr;
+using std::endl;
+
 VkCallbackObject::VkCallbackObject()
 {
 }
