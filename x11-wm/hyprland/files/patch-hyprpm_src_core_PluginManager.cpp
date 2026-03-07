Avoid hyprpm rebuilding Hyprland outside of ports

--- hyprpm/src/core/PluginManager.cpp.orig	2026-03-03 21:08:11 UTC
+++ hyprpm/src/core/PluginManager.cpp
@@ -402,9 +402,6 @@ eHeadersErrors CPluginManager::headersValid() {
 eHeadersErrors CPluginManager::headersValid() {
     const auto HLVER = getHyprlandVersion(false);
 
-    if (!std::filesystem::exists(DataState::getHeadersPath() + "/share/pkgconfig/hyprland.pc"))
-        return HEADERS_MISSING;
-
     // find headers commit
     const std::string& cmd     = std::format("PKG_CONFIG_PATH=\"{}\" pkgconf --cflags --keep-system-cflags hyprland", getPkgConfigPath());
     auto               headers = execAndGet(cmd);
