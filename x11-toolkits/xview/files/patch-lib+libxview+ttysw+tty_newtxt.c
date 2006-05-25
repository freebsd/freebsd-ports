--- lib/libxview/ttysw/tty_newtxt.c.orig	Sun Mar 26 00:27:19 2006
+++ lib/libxview/ttysw/tty_newtxt.c	Sun Mar 26 00:27:49 2006
@@ -34,6 +34,7 @@
  */
 
 
+#include <X11/Xlibint.h>
 #include <xview/window.h>
 #include <xview_private/pw_impl.h>
 #include <pixrect/pixrect.h>
