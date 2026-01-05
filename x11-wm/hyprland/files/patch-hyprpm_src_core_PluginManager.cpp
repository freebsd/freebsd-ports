Avoid hyprpm rebuilding Hyprland outside of ports

--- hyprpm/src/core/PluginManager.cpp.orig	2026-01-02 21:24:24 UTC
+++ hyprpm/src/core/PluginManager.cpp
@@ -385,9 +385,6 @@ eHeadersErrors CPluginManager::headersValid() {
 eHeadersErrors CPluginManager::headersValid() {
     const auto HLVER = getHyprlandVersion(false);
 
-    if (!std::filesystem::exists(DataState::getHeadersPath() + "/share/pkgconfig/hyprland.pc"))
-        return HEADERS_MISSING;
-
     // find headers commit
     const std::string& cmd     = std::format("PKG_CONFIG_PATH=\"{}/share/pkgconfig\" pkgconf --cflags --keep-system-cflags hyprland", DataState::getHeadersPath());
     auto               headers = execAndGet(cmd);
