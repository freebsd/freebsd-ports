--- ./VkComponent.C.orig	Wed Jul 23 02:12:18 2003
+++ ./VkComponent.C	Wed Jul 23 02:13:09 2003
@@ -46,6 +46,10 @@
 #include <Vk/VkComponent.h>
 #include <Vk/VkApp.h>
 
+using std::string;
+using std::cerr;
+using std::endl;
+
 const char *const VkComponent::deleteCallback = "VkComponentDeleteCallback";
 
 VkComponent::VkComponent(const char *name)
