--- lib/libxview/defaults/defaults.c.orig	Sat Oct  4 21:06:17 2003
+++ lib/libxview/defaults/defaults.c	Sat Oct  4 21:39:32 2003
@@ -24,7 +24,11 @@
 #include <xview/server.h>
 #endif
 #include <xview/xv_error.h>
+#ifdef X11R6
+#include <X11/Xlibint.h>
+#else
 #include <X11/Xlib.h>
+#endif
 #include <X11/Xatom.h>
 #include <X11/Xresource.h>
 #include <xview_private/i18n_impl.h>
