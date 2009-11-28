--- include/wx/gtk/win_gtk.h.orig	2009-11-27 01:59:18.000000000 +0100
+++ include/wx/gtk/win_gtk.h	2009-11-27 01:59:33.000000000 +0100
@@ -15,7 +15,9 @@
 extern "C" {
 #endif /* __cplusplus */
 
+#define GSocket GlibGSocket
 #include <gtk/gtkcontainer.h>
+#undef GSocket
 
 #include "wx/dlimpexp.h"
 
