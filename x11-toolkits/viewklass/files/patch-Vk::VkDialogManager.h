--- ./Vk/VkDialogManager.h.orig	Wed Jul 23 02:13:42 2003
+++ ./Vk/VkDialogManager.h	Wed Jul 23 02:13:57 2003
@@ -49,6 +49,8 @@
 #include <Vk/VkResource.h>
 #include <Vk/VkSimpleWindow.h>
 
+using std::string;
+
 class VkDialogManager : public VkComponent {
 public:
     typedef enum {OK, APPLY, CANCEL} VkDialogReason;
