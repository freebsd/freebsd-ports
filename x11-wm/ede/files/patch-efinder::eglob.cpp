--- efinder/eglob.cpp.orig	Sat Feb 28 04:48:43 2004
+++ efinder/eglob.cpp	Sat Feb 28 04:49:07 2004
@@ -74,14 +74,14 @@
 
 static char *ftypes[9] =
 {
-    {"Any kind"},
-    {"Regular"},
-    {"Directory"},
-    {"Symlink"},
-    {"Socket"},
-    {"Block device"},
-    {"Character device"},
-    {"FIFO"},
+    "Any kind",
+    "Regular",
+    "Directory",
+    "Symlink",
+    "Socket",
+    "Block device",
+    "Character device",
+    "FIFO",
     NULL
 };
 
