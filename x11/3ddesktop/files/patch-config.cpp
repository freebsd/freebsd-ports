--- config.cpp.orig	2005-06-20 11:20:44 UTC
+++ config.cpp
@@ -64,8 +64,9 @@ get_boolean (char *value) 
 }
 
 
-Options::Options(char *n = NULL) 
+Options::Options(char *n) 
 {
+    n = NULL;
 
     if (n)
         strncpy(name, n, sizeof(name));
