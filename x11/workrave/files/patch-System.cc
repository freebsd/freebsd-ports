--- frontend/common/src/System.cc.old      2011-05-17 11:54:41.000000000 -0500
+++ frontend/common/src/System.cc   2011-05-17 11:55:13.000000000 -0500
@@ -41,15 +41,12 @@
 #include <X11/Xproto.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
+#include <sys/wait.h>
 #ifdef HAVE_APP_GTK
 #include <gdk/gdkx.h>
 #endif
 #endif
 
-#if defined(HAVE_UNIX)
-#include <sys/wait.h>
-#endif
-
 #ifdef PLATFORM_OS_WIN32
 #include <shlobj.h>
 #include <shldisp.h>

