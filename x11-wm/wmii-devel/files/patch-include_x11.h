--- include/x11.h.orig	2020-10-18 08:56:29 UTC
+++ include/x11.h
@@ -17,6 +17,10 @@
 #undef Font
 #undef Screen
 
+#ifndef EXTERN
+#   define EXTERN extern
+#endif
+
 enum Align {
 	North = 0x01,
 	East  = 0x02,
@@ -182,8 +186,8 @@ struct Screen {
 # pragma varargck	type	"W"	Window*	
 #endif
 
-Display *display;
-Screen scr;
+EXTERN Display *display;
+EXTERN Screen scr;
 
 extern const Point ZP;
 extern const Rectangle ZR;
