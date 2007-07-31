--- Client.C.orig	2007-07-31 22:18:48.000000000 +0200
+++ Client.C	2007-07-31 22:19:06.000000000 +0200
@@ -410,7 +410,7 @@
 
     x = *p;
     XFree((void *)p);
-    return (int)x;
+    return (intptr_t)x;
 }
 
 
