--- setup.py.orig	2023-10-03 11:21:49 UTC
+++ setup.py
@@ -269,7 +269,7 @@ evdi_ENABLED            = DEFAULT and LINUX and pkg_co
 keyboard_ENABLED        = DEFAULT
 v4l2_ENABLED            = DEFAULT and (not WIN32 and not OSX and not FREEBSD and not OPENBSD)
 evdi_ENABLED            = DEFAULT and LINUX and pkg_config_version("1.9", "evdi")
-drm_ENABLED             = DEFAULT and LINUX and pkg_config_version("2.4", "libdrm")
+drm_ENABLED             = DEFAULT and (LINUX or FREEBSD) and pkg_config_version("2.4", "libdrm")
 #ffmpeg 3.1 or later is required
 dec_avcodec2_ENABLED    = ffmpeg_ENABLED and pkg_config_version("57", "libavcodec")
 csc_swscale_ENABLED     = ffmpeg_ENABLED and pkg_config_ok("--exists", "libswscale")
@@ -2043,7 +2002,7 @@ if data_ENABLED:
     if not is_openSUSE():
         add_data_files(share_xpra,                  ["README.md", "COPYING"])
     add_data_files(share_xpra,                      ["fs/share/xpra/bell.wav"])
-    if LINUX:
+    if LINUX or FREEBSD:
         add_data_files(share_xpra,                  ["fs/share/xpra/autostart.desktop"])
     ICONS = glob.glob("fs/share/xpra/icons/*.png")
     if OSX:
