--- src/Helpers.cpp.orig	2021-08-07 07:23:04 UTC
+++ src/Helpers.cpp
@@ -83,7 +83,7 @@ namespace Help
 		{
 			char buffer[1024];
 			strcpy(buffer, str.c_str());
-			return basename(buffer);
+			return g_path_get_basename(buffer);
 		}
 
 		std::string trim(const std::string str)
