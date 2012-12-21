--- Ck.cpp.orig	2012-02-22 03:59:52.000000000 +0400
+++ Ck.cpp	2012-07-19 00:03:34.000000000 +0400
@@ -91,7 +91,7 @@
 
     vt = *((long *)return_value);
 
-    std::snprintf(device, 32, "/dev/tty%ld", vt);
+    std::snprintf(device, 32, "/dev/ttyv%ld", vt - 1);
 
     if(return_value)
       XFree(return_value);
