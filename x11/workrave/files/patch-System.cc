--- frontend/common/src/System.cc.old	2010-03-25 11:16:41.000000000 -0700
+++ frontend/common/src/System.cc	2010-03-25 11:16:55.000000000 -0700
@@ -41,9 +41,6 @@
 #include <X11/Xproto.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
-#endif
-
-#if defined(HAVE_UNIX)
 #include <sys/wait.h>
 #endif
 
