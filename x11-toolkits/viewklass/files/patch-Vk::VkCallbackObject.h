--- ./Vk/VkCallbackObject.h.orig	Wed Jul 23 02:07:33 2003
+++ ./Vk/VkCallbackObject.h	Wed Jul 23 02:07:48 2003
@@ -42,6 +42,8 @@
 
 #include <Vk/VkConfig.h>
 
+using std::vector;
+
 class VkCallbackObject;
 
 typedef void (VkCallbackObject::*VkCallbackMethod)(
