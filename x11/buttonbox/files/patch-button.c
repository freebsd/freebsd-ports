
$FreeBSD$

--- button.c.orig
+++ button.c
@@ -31,7 +31,7 @@
 
 
 
-static char* default_font = "7x13";
+char* default_font = "7x13";
 
 static Bool button_window_proc (Dispatcher* dispatcher, XEvent* event, void* data);
 
