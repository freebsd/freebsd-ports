--- include/wx/propgrid/editors.h.orig	2022-10-15 19:03:21 UTC
+++ include/wx/propgrid/editors.h
@@ -13,6 +13,10 @@
 
 #include "wx/defs.h"
 
+#if wxUSE_BMPBUTTON
+#include "wx/bmpbndl.h"
+#endif
+
 #if wxUSE_PROPGRID
 
 #include "wx/window.h"
