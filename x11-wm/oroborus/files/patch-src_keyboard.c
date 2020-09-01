--- src/keyboard.c.orig	2006-01-12 15:40:43 UTC
+++ src/keyboard.c
@@ -35,6 +35,8 @@
 #include <stdio.h>
 #endif
 
+int NumLockMask, CapsLockMask, ScrollLockMask;
+
 void
 parseKeyString (Display * dpy, MyKey * key, char *str)
 {
