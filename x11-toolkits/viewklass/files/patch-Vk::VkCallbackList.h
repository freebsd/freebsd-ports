--- ./Vk/VkCallbackList.h.orig	Wed Jul 23 02:06:54 2003
+++ ./Vk/VkCallbackList.h	Wed Jul 23 02:07:15 2003
@@ -44,6 +44,9 @@
 #include <Vk/VkComponent.h>
 #include <Vk/VkCallbackObject.h>
 
+using std::vector;
+using std::string;
+
 struct VkCallbackListEntry {
     enum CallbackType type;
     VkCallbackObject *component;
