$FreeBSD$

--- libAfterStep/mylook.h.orig	2014-04-12 12:24:55.000000000 -0700
+++ libAfterStep/mylook.h	2014-04-12 12:25:46.000000000 -0700
@@ -411,9 +411,9 @@
 
 
 struct MyStyle *mylook_get_style(MyLook *look, const char *name);
-inline MyBackground  *mylook_get_desk_back(MyLook *look, long desk);
-inline MyBackground  *mylook_get_back(MyLook *look, char *name);
-inline MyDesktopConfig *mylook_get_desk_config(MyLook *look, long desk);
+MyBackground  *mylook_get_desk_back(MyLook *look, long desk);
+MyBackground  *mylook_get_back(MyLook *look, char *name);
+MyDesktopConfig *mylook_get_desk_config(MyLook *look, long desk);
 
 
 
