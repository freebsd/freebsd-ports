--- ./Vk/VkNameList.h.orig	Wed Jul 23 02:23:57 2003
+++ ./Vk/VkNameList.h	Wed Jul 23 02:24:28 2003
@@ -43,6 +43,9 @@
 #include <Xm/Xm.h>
 #include <Vk/VkConfig.h>
 
+using std::vector;
+using std::string;
+
 class VkNameList {
  public:
     VkNameList();
