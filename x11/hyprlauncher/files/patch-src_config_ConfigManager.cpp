--- src/config/ConfigManager.cpp.orig	2025-11-23 08:42:40 UTC
+++ src/config/ConfigManager.cpp
@@ -2,6 +2,8 @@
 
 #include "../helpers/Log.hpp"
 
+#include <unistd.h>
+
 #include <hyprutils/path/Path.hpp>
 
 CConfigManager::CConfigManager() : m_inotifyFd(inotify_init()) {
