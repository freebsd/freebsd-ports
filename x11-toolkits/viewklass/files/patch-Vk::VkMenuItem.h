--- ./Vk/VkMenuItem.h.orig	Wed Jul 23 02:22:17 2003
+++ ./Vk/VkMenuItem.h	Wed Jul 23 02:22:29 2003
@@ -41,6 +41,8 @@
 #include <Vk/VkComponent.h>
 #include <Vk/VkWidgetList.h>
 
+using std::string;
+
 typedef enum {ACTION, ACTIONWIDGET, CONFIRMFIRSTACTION, TOGGLE, LABEL,
 			  SEPARATOR, SUBMENU, RADIOSUBMENU, BAR, OPTION, POPUP, OBJECT,
 			  END} VkMenuItemType;
