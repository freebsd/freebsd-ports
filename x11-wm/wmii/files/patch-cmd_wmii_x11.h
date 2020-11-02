--- cmd/wmii/x11.h.orig	2020-10-17 20:50:09 UTC
+++ cmd/wmii/x11.h
@@ -94,8 +94,8 @@ struct Font {
 	char *name;
 };
 
-Display *display;
-Screen scr;
+extern Display *display;
+extern Screen scr;
 
 extern Point ZP;
 extern Rectangle ZR;
