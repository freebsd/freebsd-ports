--- src/keyboard.h.orig	2006-01-12 15:40:43 UTC
+++ src/keyboard.h
@@ -90,7 +90,7 @@ void grabKey (Display *, MyKey *, Window);
 void ungrabKeys (Display *, Window);
 void init_keyboard (Display * dpy);
 
-int NumLockMask, CapsLockMask, ScrollLockMask;
+extern int NumLockMask, CapsLockMask, ScrollLockMask;
 
 #endif /* __KEYBOARD_H */
 
