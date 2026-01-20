--- cmake/libpoly.cmake.orig	2026-01-20 21:56:32 UTC
+++ cmake/libpoly.cmake
@@ -102,5 +102,5 @@ if(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
 
 # FreeBSD Support
 if(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
-  find_package(LibInotify REQUIRED)
+  find_package(LibInotify)
 endif()
