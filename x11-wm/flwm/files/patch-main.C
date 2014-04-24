--- main.C.orig	2014-04-18 19:48:14.000000000 +0200
+++ main.C	2014-04-23 11:42:47.000000000 +0200
@@ -4,6 +4,7 @@
 
 #include "Frame.H"
 #include <X11/Xproto.h>
+#include <X11/XKBlib.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -102,9 +103,10 @@
       if (c->window() == window || fl_xid(c) == window)
 #if CLICK_RAISES || CLICK_TO_TYPE
 	if (fl_xevent->type == ButtonPress) {click_raise(c); return 1;}
-	else
+	else {
 #endif
 	  return c->handle(fl_xevent);
+	}
     switch (fl_xevent->type) {
     case ButtonPress:
       printf("got a button press in main\n");
@@ -124,7 +126,8 @@
     case KeyRelease:
       if (!Fl::grab()) return 0;
       Fl::e_keysym =
-	XKeycodeToKeysym(fl_display, fl_xevent->xkey.keycode, 0);
+        XkbKeycodeToKeysym(fl_display, fl_xevent->xkey.keycode,
+                0, fl_xevent->xkey.state & ShiftMask ? 1 : 0);
       goto KEYUP;
 #endif
     }
