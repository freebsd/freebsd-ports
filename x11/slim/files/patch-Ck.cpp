--- ./Ck.cpp.orig	2012-12-31 07:03:42.000000000 -0600
+++ ./Ck.cpp	2013-03-23 14:10:35.000000000 -0500
@@ -91,7 +91,7 @@
 
 	vt = *((long *)return_value);
 
-	std::snprintf(device, 32, "/dev/tty%ld", vt);
+	snprintf(device, 32, "/dev/ttyv%ld", vt - 1);
 
 	if(return_value)
 	  XFree(return_value);
