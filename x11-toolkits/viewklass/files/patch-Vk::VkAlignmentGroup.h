--- ./Vk/VkAlignmentGroup.h.orig	Wed Jul 23 02:43:07 2003
+++ ./Vk/VkAlignmentGroup.h	Wed Jul 23 02:45:35 2003
@@ -24,6 +24,9 @@
 
 #include <Vk/VkWidgetList.h>
 #include <Vk/VkOptionMenu.h>
+#include <iostream>
+
+using std::ostream;
 
 class VkAlignmentGroup : public VkWidgetList {
 public:
