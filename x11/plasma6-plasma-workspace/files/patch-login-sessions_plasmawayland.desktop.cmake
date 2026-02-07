--- login-sessions/plasmawayland.desktop.cmake.orig	2025-02-06 11:03:03 UTC
+++ login-sessions/plasmawayland.desktop.cmake
@@ -1,5 +1,5 @@
 [Desktop Entry]
-Exec=@CMAKE_INSTALL_FULL_LIBEXECDIR@/plasma-dbus-run-session-if-needed ${CMAKE_INSTALL_FULL_BINDIR}/startplasma-wayland
+Exec=@CMAKE_INSTALL_FULL_LIBEXECDIR@/plasma-dbus-run-session-if-needed %%LOCALBASE%%/bin/ck-launch-session ${CMAKE_INSTALL_FULL_BINDIR}/startplasma-wayland
 TryExec=${CMAKE_INSTALL_FULL_BINDIR}/startplasma-wayland
 DesktopNames=KDE
 Name=Plasma (Wayland)
