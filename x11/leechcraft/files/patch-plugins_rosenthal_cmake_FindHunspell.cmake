--- plugins/rosenthal/cmake/FindHunspell.cmake.orig	2014-07-28 18:35:44 UTC
+++ plugins/rosenthal/cmake/FindHunspell.cmake
@@ -28,7 +28,8 @@ if (WIN32)
 		${HUNSPELL_DIR}/src/win_api/Release_dll/libhunspell)
 endif ()
 
-find_library (HUNSPELL_LIBRARIES NAMES hunspell-1.3 hunspell-1.2 libhunspell HINTS ${HUNSPELL_DIR} ${PROBE_DIR})
+find_library (HUNSPELL_LIBRARIES NAMES hunspell-1.5 hunspell-1.4
+	hunspell-1.3 hunspell-1.2 libhunspell HINTS ${HUNSPELL_DIR} ${PROBE_DIR})
 find_path (HUNSPELL_INCLUDE_DIR hunspell/hunspell.hxx HINTS ${HUNSPELL_DIR} ${HUNSPELL_INCLUDE_WIN32})
 
 # handle the QUIETLY and REQUIRED arguments and set HUNSPELL_FOUND to TRUE if
