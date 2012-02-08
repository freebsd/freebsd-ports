--- lib/libxview/defaults/defaults.c.orig	2005-03-28 06:41:45.000000000 -0800
+++ lib/libxview/defaults/defaults.c	2012-02-02 16:50:29.447421571 -0800
@@ -24,8 +24,7 @@
 #include <xview/server.h>
 #endif
 #include <xview/xv_error.h>
-/* mbuck@debian.org */
-#if 1
+#ifdef X11R6
 #include <X11/Xlibint.h>
 #else
 #include <X11/Xlib.h>
