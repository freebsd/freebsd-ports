--- Ck.cpp.orig	2020-02-15 19:48:07 UTC
+++ Ck.cpp
@@ -91,7 +91,7 @@ namespace Ck {
 
 	vt = *((long *)return_value);
 
-	std::snprintf(device, 32, "/dev/tty%ld", vt);
+	std::snprintf(device, 32, "/dev/ttyv%ld", vt-1);
 
 	if(return_value)
 	  XFree(return_value);
