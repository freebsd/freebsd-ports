--- src/x11.cc.orig	2012-12-31 01:07:34.000000000 +0100
+++ src/x11.cc	2012-12-31 01:11:01.000000000 +0100
@@ -993,6 +993,8 @@
 /**
  * Wrapper for XKeycodeToKeysym and XkbKeycodeToKeysym depending on which one is available.
  */
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
 KeySym
 X11::getKeysymFromKeycode(KeyCode keycode)
 {
@@ -1001,12 +1003,9 @@
         return XkbKeycodeToKeysym(_dpy, keycode, 0, 0);
     else
 #endif
-
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
         return XKeycodeToKeysym(_dpy, keycode, 0);
-#pragma GCC diagnostic pop
 }
+#pragma GCC diagnostic pop
 
 Display *X11::_dpy;
 bool X11::_honour_randr = false;
