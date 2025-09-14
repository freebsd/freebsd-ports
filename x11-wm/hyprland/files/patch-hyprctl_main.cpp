--- hyprctl/main.cpp.orig	2025-09-10 12:53:39 UTC
+++ hyprctl/main.cpp
@@ -270,7 +270,7 @@ int requestIPC(std::string_view filename, std::string_
     sockaddr_un serverAddress = {0};
     serverAddress.sun_family  = AF_UNIX;
 
-    std::string socketPath = getRuntimeDir() + "/" + instanceSignature + "/" + filename;
+    std::string socketPath = getRuntimeDir() + "/" + instanceSignature + "/" + std::string(filename);
 
     strncpy(serverAddress.sun_path, socketPath.c_str(), sizeof(serverAddress.sun_path) - 1);
 
