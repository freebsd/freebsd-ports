--- ./Vk/VkPrefItem.h.orig	Wed Jul 23 02:40:46 2003
+++ ./Vk/VkPrefItem.h	Wed Jul 23 02:41:01 2003
@@ -45,6 +45,8 @@
 
 #include <string>
 
+using std::string;
+
 class VkPrefItem : public VkComponent {
 public:
     enum VkPrefItemType {PI_group, PI_list, PI_radio, PI_text, PI_toggle,
