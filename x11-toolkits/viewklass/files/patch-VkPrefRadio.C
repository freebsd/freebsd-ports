--- ./VkPrefRadio.C.orig	Wed Jul 23 02:42:07 2003
+++ ./VkPrefRadio.C	Wed Jul 23 02:42:38 2003
@@ -40,6 +40,10 @@
 #include <Xm/Form.h>
 
 #include <Vk/VkPrefRadio.h>
+#include <iostream>
+
+using std::cerr;
+using std::endl;
 
 // A VkPrefRadio is a vertical VkPrefGroup with no label
 VkPrefRadio::VkPrefRadio(const char *name,
