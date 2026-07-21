Avoid hyprpm rebuilding Hyprland outside of ports

--- hyprpm/src/core/PluginManager.cpp.orig	2026-07-20 08:36:36 UTC
+++ hyprpm/src/core/PluginManager.cpp
@@ -414,9 +414,6 @@ eHeadersErrors CPluginManager::headersValid() {
 eHeadersErrors CPluginManager::headersValid() {
     const auto HLVER = getHyprlandVersion(false);
 
-    if (!std::filesystem::exists(DataState::getHeadersPath() + "/share/pkgconfig/hyprland.pc"))
-        return HEADERS_MISSING;
-
     // find headers commit
     const std::string& cmd     = std::format("PKG_CONFIG_PATH=\"{}\" pkgconf --cflags --keep-system-cflags hyprland", getPkgConfigPath());
     auto               headers = execAndGet(cmd);
