--- pango/pangoxft.h.orig	Sun Oct  6 23:03:37 2002
+++ pango/pangoxft.h	Sun Oct  6 23:03:42 2002
@@ -31,7 +31,7 @@
 #define _XFT_NO_COMPAT
 #define _XFTCOMPAT_H_
 #include <X11/Xlib.h>
-#include <X11/Xft/Xft.h>
+#include <X11/Xft/Xft2.h>
 #if defined(XftVersion) && XftVersion >= 20000
 #else
 #error "must have Xft version 2 or newer"
