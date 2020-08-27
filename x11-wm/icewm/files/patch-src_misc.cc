--- src/misc.cc.orig	2020-08-24 22:02:15 UTC
+++ src/misc.cc
@@ -972,7 +972,8 @@ char* path_lookup(const char* name) {
     if (env == nullptr)
         return nullptr;
 
-    while ((directory = strtok_r(save ? nullptr : env, ":", &save)) != nullptr) {
+    for (directory = strtok_r(env, ":", &save); directory != nullptr;
+      directory = strtok_r(nullptr, ":", &save)) {
         size_t length = strlen(directory) + strlen(name) + 3;
         filebuf = new char[length];
         if (filebuf == nullptr)
