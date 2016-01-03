--- plugins/lmp/cmake/FindTaglib.cmake.orig	2016-01-03 16:39:26 UTC
+++ plugins/lmp/cmake/FindTaglib.cmake
@@ -29,7 +29,7 @@ if(TAGLIBCONFIG_EXECUTABLE)
 
   exec_program(${TAGLIBCONFIG_EXECUTABLE} ARGS --version RETURN_VALUE _return_VALUE OUTPUT_VARIABLE TAGLIB_VERSION)
 
-  if(TAGLIB_VERSION STRLESS "${TAGLIB_MIN_VERSION}")
+  if(TAGLIB_VERSION VERSION_LESS "${TAGLIB_MIN_VERSION}")
      message(STATUS "TagLib version not found: version searched :${TAGLIB_MIN_VERSION}, found ${TAGLIB_VERSION}")
      set(TAGLIB_FOUND FALSE)
   else()
