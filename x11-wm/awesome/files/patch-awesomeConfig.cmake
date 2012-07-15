--- awesomeConfig.cmake.orig	2012-07-15 07:12:21.000000000 -0300
+++ awesomeConfig.cmake	2012-07-15 20:30:48.000000000 -0300
@@ -13,7 +13,8 @@
 option(WITH_DBUS "build with D-BUS" ON)
 option(GENERATE_MANPAGES "generate manpages" ON)
 option(COMPRESS_MANPAGES "compress manpages" ON)
-option(GENERATE_LUADOC "generate luadoc" ON)
+option(GENERATE_LUADOC "generate luadoc" OFF)
+option(INSTALL_PORTDOCS "install port docs" ON)
 
 # {{{ CFLAGS
 add_definitions(-std=gnu99 -ggdb3 -fno-strict-aliasing -Wall -Wextra
@@ -59,7 +60,7 @@
 # theme graphics
 a_find_program(CONVERT_EXECUTABLE convert TRUE)
 # doxygen
-include(FindDoxygen)
+#include(FindDoxygen)
 # pkg-config
 include(FindPkgConfig)
 # lua 5.1
@@ -162,6 +163,8 @@
 
 # Check for libev
 a_find_library(LIB_EV ev)
+# Check for libexecinfo on non Glibc system
+a_find_library(LIB_EXECINFO execinfo)
 
 # Check for backtrace_symbols()
 include(CheckFunctionExists)
@@ -200,6 +203,7 @@
     ${AWESOME_COMMON_REQUIRED_LDFLAGS}
     ${AWESOME_REQUIRED_LDFLAGS}
     ${LIB_EV}
+    ${LIB_EXECINFO}
     ${LUA_LIBRARIES})
 
 set(AWESOME_REQUIRED_INCLUDE_DIRS
@@ -261,7 +265,7 @@
 if(DEFINED AWESOME_MAN_PATH)
    set(AWESOME_MAN_PATH ${AWESOME_MAN_PATH} CACHE PATH "awesome manpage directory")
 else()
-   set(AWESOME_MAN_PATH ${CMAKE_INSTALL_PREFIX}/share/man CACHE PATH "awesome manpage directory")
+   set(AWESOME_MAN_PATH ${CMAKE_INSTALL_PREFIX}/man CACHE PATH "awesome manpage directory")
 endif()
 
 # Hide to avoid confusion
