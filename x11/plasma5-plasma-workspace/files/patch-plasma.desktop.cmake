--- plasma.desktop.cmake.orig	2018-05-05 17:27:16 UTC
+++ plasma.desktop.cmake
@@ -1,6 +1,6 @@
 [Desktop Entry]
 Type=XSession
-Exec=${CMAKE_INSTALL_FULL_BINDIR}/startkde
+Exec=ck-launch-session ${CMAKE_INSTALL_FULL_BINDIR}/startkde
 TryExec=${CMAKE_INSTALL_FULL_BINDIR}/startkde
 DesktopNames=KDE
 Name=Plasma
