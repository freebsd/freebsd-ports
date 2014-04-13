$FreeBSD$

--- libAfterStep/mylook.c.orig	2014-04-12 12:25:04.000000000 -0700
+++ libAfterStep/mylook.c	2014-04-12 12:26:22.000000000 -0700
@@ -843,7 +843,7 @@
 	return NULL;
 }
 
-inline MyDesktopConfig *mylook_get_desk_config (MyLook * look, long desk)
+MyDesktopConfig *mylook_get_desk_config (MyLook * look, long desk)
 {
 	if (look) {
 		ASHashData hdata = { 0 };
@@ -856,7 +856,7 @@
 }
 
 
-inline MyBackground *mylook_get_desk_back (MyLook * look, long desk)
+MyBackground *mylook_get_desk_back (MyLook * look, long desk)
 {
 	MyBackground *myback = NULL;
 
@@ -888,7 +888,7 @@
 }
 
 
-inline MyBackground *mylook_get_back (MyLook * look, char *name)
+MyBackground *mylook_get_back (MyLook * look, char *name)
 {
 	ASHashData hdata = { 0 };
 	if (look && name)
