--- main.c.orig	2021-02-02 00:20:59 UTC
+++ main.c
@@ -110,6 +110,12 @@
 #include <X11/XawPlus/Form.h>
 #endif
 
+#else
+
+#if defined(HAVE_LIB_XAW3DXFT)
+#include <X11/Xaw3dxft/Xaw3dXft.h>
+#endif
+
 #endif /* OPT_TOOLBAR */
 
 #include <pwd.h>
