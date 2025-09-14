--- src/render/OpenGL.cpp.orig	2025-09-13 08:51:11 UTC
+++ src/render/OpenGL.cpp
@@ -2876,7 +2876,7 @@ void CHyprOpenGLImpl::ensureBackgroundTexturePresence(
     static auto PNOWALLPAPER    = CConfigValue<Hyprlang::INT>("misc:disable_hyprland_logo");
     static auto PFORCEWALLPAPER = CConfigValue<Hyprlang::INT>("misc:force_default_wallpaper");
 
-    const auto  FORCEWALLPAPER = std::clamp(*PFORCEWALLPAPER, -1L, 2L);
+    const auto  FORCEWALLPAPER = std::clamp(*PFORCEWALLPAPER, static_cast<Hyprlang::INT>(-1), static_cast<Hyprlang::INT>(2));
 
     if (*PNOWALLPAPER)
         m_backgroundTexture.reset();
