--- awesomeConfig.cmake.orig	2009-09-28 09:08:15.000000000 -0300
+++ awesomeConfig.cmake	2009-09-30 16:36:56.000000000 -0300
@@ -11,8 +11,9 @@
 set(CMAKE_BUILD_TYPE RELEASE)
 
 option(WITH_DBUS "build with D-BUS" ON)
+option(INSTALL_PORTDOCS "install port docs" ON)
 option(GENERATE_MANPAGES "generate manpages" ON)
-option(GENERATE_LUADOC "generate luadoc" ON)
+option(GENERATE_LUADOC "generate luadoc" OFF)
 
 link_directories(/usr/local/lib)
 
@@ -60,7 +61,7 @@
 # theme graphics
 a_find_program(CONVERT_EXECUTABLE convert TRUE)
 # doxygen
-include(FindDoxygen)
+#include(FindDoxygen)
 # pkg-config
 include(FindPkgConfig)
 # lua 5.1
@@ -166,6 +167,8 @@
 
 # Check for libev
 a_find_library(LIB_EV ev)
+# Check for libexecinfo on non Glibc system
+a_find_library(LIB_EXECINFO execinfo)
 
 # Error check
 if(NOT LUA51_FOUND AND NOT LUA50_FOUND) # This is a workaround to a cmake bug
@@ -176,6 +179,7 @@
     ${AWESOME_COMMON_REQUIRED_LDFLAGS}
     ${AWESOME_REQUIRED_LIBRARIES}
     ${LIB_EV}
+    ${LIB_EXECINFO}
     ${LUA_LIBRARIES})
 
 set(AWESOME_REQUIRED_INCLUDE_DIRS
@@ -244,7 +248,7 @@
 if(DEFINED AWESOME_MAN_PATH)
    set(AWESOME_MAN_PATH ${AWESOME_MAN_PATH} CACHE PATH "awesome manpage directory")
 else()
-   set(AWESOME_MAN_PATH ${PREFIX}/share/man CACHE PATH "awesome manpage directory")
+   set(AWESOME_MAN_PATH ${PREFIX}/man CACHE PATH "awesome manpage directory")
 endif()
 
 # Hide to avoid confusion
