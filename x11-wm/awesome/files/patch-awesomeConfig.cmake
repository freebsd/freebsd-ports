--- awesomeConfig.cmake.orig	2009-01-08 12:04:44.000000000 +0200
+++ awesomeConfig.cmake	2009-02-01 00:11:33.000000000 +0200
@@ -14,8 +14,9 @@
 set(CURSES_NEED_NCURSES true)
 
 option(WITH_DBUS "build with D-BUS" ON)
+option(INSTALL_PORTDOCS "install port docs" ON)
 option(GENERATE_MANPAGES "generate manpages" ON)
-option(GENERATE_LUADOC "generate luadoc" ON)
+option(GENERATE_LUADOC "generate luadoc" OFF)
 
 link_directories(/usr/local/lib)
 
@@ -134,14 +135,14 @@
     cairo
     pango
     pangocairo
-    x11-xcb
+    xcb
     xcb-randr
     xcb-xinerama
     xcb-event>=0.3.0
     xcb-aux>=0.3.0
     xcb-atom>=0.3.0
     xcb-keysyms>=0.3.0
-    xcb-icccm>=0.3.0
+    xcb-icccm>=0.3.3
     cairo-xcb
     xproto>=7.0.11
     imlib2)
@@ -248,7 +249,7 @@
 if(DEFINED AWESOME_MAN_PATH)
    set(AWESOME_MAN_PATH ${AWESOME_MAN_PATH} CACHE PATH "awesome manpage directory")
 else()
-   set(AWESOME_MAN_PATH ${PREFIX}/share/man CACHE PATH "awesome manpage directory")
+   set(AWESOME_MAN_PATH ${PREFIX}/man CACHE PATH "awesome manpage directory")
 endif()
 
 # Hide to avoid confusion
