--- ./VkAlignmentGroup.C.orig	Wed Jul 23 02:44:15 2003
+++ ./VkAlignmentGroup.C	Wed Jul 23 02:45:22 2003
@@ -36,6 +36,8 @@
 
 #include <Vk/VkAlignmentGroup.h>
 
+using std::endl;
+
 VkAlignmentGroup::VkAlignmentGroup()
 	: VkWidgetList(),
 	  _maxWidth(0),
