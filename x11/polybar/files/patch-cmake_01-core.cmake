--- cmake/01-core.cmake.orig	2017-12-03 17:03:49 UTC
+++ cmake/01-core.cmake
@@ -31,8 +31,17 @@ set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic-errors")
 
+if (CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+  # Need dprintf() for FreeBSD 11.1 and older
+  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_WITH_DPRINTF")
+
+  # libinotify uses c99 extension, so suppress this error
+  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-c99-extensions")
+endif()
+
 if(${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=parentheses-equality")
+  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-zero-length-array")
 endif()
 
 set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
