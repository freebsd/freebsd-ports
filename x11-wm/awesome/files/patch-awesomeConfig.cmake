--- awesomeConfig.cmake.orig	2010-01-04 06:50:02.000000000 -0200
+++ awesomeConfig.cmake	2010-01-04 08:06:18.000000000 -0200
@@ -13,7 +13,8 @@
 option(WITH_DBUS "build with D-BUS" ON)
 option(GENERATE_MANPAGES "generate manpages" ON)
 option(COMPRESS_MANPAGES "compress manpages" ON)
-option(GENERATE_LUADOC "generate luadoc" ON)
+option(GENERATE_LUADOC "generate luadoc" OFF)
+option(INSTALL_PORTDOCS "install port docs" ON)
 
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
@@ -167,6 +168,8 @@
 
 # Check for libev
 a_find_library(LIB_EV ev)
+# Check for libexecinfo on non Glibc system
+a_find_library(LIB_EXECINFO execinfo)
 
 # Error check
 if(NOT LUA51_FOUND AND NOT LUA50_FOUND) # This is a workaround to a cmake bug
@@ -177,6 +180,7 @@
     ${AWESOME_COMMON_REQUIRED_LDFLAGS}
     ${AWESOME_REQUIRED_LIBRARIES}
     ${LIB_EV}
+    ${LIB_EXECINFO}
     ${LUA_LIBRARIES})
 
 set(AWESOME_REQUIRED_INCLUDE_DIRS
@@ -245,7 +249,7 @@
 if(DEFINED AWESOME_MAN_PATH)
    set(AWESOME_MAN_PATH ${AWESOME_MAN_PATH} CACHE PATH "awesome manpage directory")
 else()
-   set(AWESOME_MAN_PATH ${PREFIX}/share/man CACHE PATH "awesome manpage directory")
+   set(AWESOME_MAN_PATH ${PREFIX}/man CACHE PATH "awesome manpage directory")
 endif()
 
 # Hide to avoid confusion
