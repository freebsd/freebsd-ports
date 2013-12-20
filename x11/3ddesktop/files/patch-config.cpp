--- config.cpp.orig
+++ config.cpp
@@ -64,8 +64,9 @@
 }
 
 
-Options::Options(char *n = NULL) 
+Options::Options(char *n) 
 {
+    n = NULL;
 
     if (n)
         strncpy(name, n, sizeof(name));
