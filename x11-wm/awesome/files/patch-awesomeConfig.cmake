--- awesomeConfig.cmake.orig	2016-01-15 15:51:19 UTC
+++ awesomeConfig.cmake
@@ -14,6 +14,7 @@ option(WITH_DBUS "build with D-BUS" ON)
 option(GENERATE_MANPAGES "generate manpages" ON)
 option(COMPRESS_MANPAGES "compress manpages" ON)
 option(GENERATE_DOC "generate API documentation" ON)
+option(INSTALL_PORTDOCS "install port docs" ON)
 
 # {{{ CFLAGS
 add_definitions(-O1 -std=gnu99 -ggdb3 -rdynamic -fno-strict-aliasing -Wall -Wextra
@@ -61,7 +62,7 @@ endif()
 # theme graphics
 a_find_program(CONVERT_EXECUTABLE convert TRUE)
 # doxygen
-include(FindDoxygen)
+#include(FindDoxygen)
 # pkg-config
 include(FindPkgConfig)
 # lua 5.1
@@ -264,7 +265,7 @@ endif()
 if(DEFINED AWESOME_MAN_PATH)
    set(AWESOME_MAN_PATH ${AWESOME_MAN_PATH} CACHE PATH "awesome manpage directory")
 else()
-   set(AWESOME_MAN_PATH ${CMAKE_INSTALL_PREFIX}/share/man CACHE PATH "awesome manpage directory")
+   set(AWESOME_MAN_PATH ${CMAKE_INSTALL_PREFIX}/man CACHE PATH "awesome manpage directory")
 endif()
 
 # Hide to avoid confusion
