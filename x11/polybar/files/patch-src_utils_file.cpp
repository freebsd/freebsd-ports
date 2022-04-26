--- src/utils/file.cpp.orig	2022-03-27 18:43:31 UTC
+++ src/utils/file.cpp
@@ -322,7 +322,7 @@ namespace file_util {
       possible_paths.push_back(xdg_config_dir + suffix + ".ini");
     }
 
-    possible_paths.push_back("/etc" + suffix + ".ini");
+    possible_paths.push_back("${CMAKE_INSTALL_PREFIX}/etc" + suffix + ".ini");
 
     for (const string& p : possible_paths) {
       if (exists(p)) {
