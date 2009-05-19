--- awesomeConfig.cmake.orig
+++ awesomeConfig.cmake
@@ -12,8 +12,9 @@
 set(CMAKE_BUILD_TYPE RELEASE)
 
 option(WITH_DBUS "build with D-BUS" ON)
+option(INSTALL_PORTDOCS "install port docs" ON)
 option(GENERATE_MANPAGES "generate manpages" ON)
-option(GENERATE_LUADOC "generate luadoc" ON)
+option(GENERATE_LUADOC "generate luadoc" OFF)
 
 link_directories(/usr/local/lib)
 
@@ -61,7 +62,7 @@
 # theme graphics
 a_find_program(CONVERT_EXECUTABLE convert TRUE)
 # doxygen
-include(FindDoxygen)
+#include(FindDoxygen)
 # pkg-config
 include(FindPkgConfig)
 # lua 5.1
@@ -244,7 +245,7 @@
 if(DEFINED AWESOME_MAN_PATH)
    set(AWESOME_MAN_PATH ${AWESOME_MAN_PATH} CACHE PATH "awesome manpage directory")
 else()
-   set(AWESOME_MAN_PATH ${PREFIX}/share/man CACHE PATH "awesome manpage directory")
+   set(AWESOME_MAN_PATH ${PREFIX}/man CACHE PATH "awesome manpage directory")
 endif()
 
 # Hide to avoid confusion
