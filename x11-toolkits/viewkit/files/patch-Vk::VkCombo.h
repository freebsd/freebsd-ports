--- ./Vk/VkCombo.h.orig	Wed Aug 16 23:50:14 2000
+++ ./Vk/VkCombo.h	Wed Aug 16 23:31:48 2000
@@ -22,7 +22,12 @@
 #include <Vk/VkConfig.h>
 #include <Vk/VkComponent.h>
 #ifdef USE_MOTIF20
+#   ifdef OPEN_MOTIF
+#include <Xm/ComboBoxP.h>
+#include <Xm/TextF.h>
+#   else
 #include <Xm/ComboBox.h>
+#   endif
 #else
 #include <Vk/ComboBox.h>
 #endif
