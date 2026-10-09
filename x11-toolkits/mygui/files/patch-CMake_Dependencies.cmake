--- CMake/Dependencies.cmake.orig	2026-06-15 20:24:08 UTC
+++ CMake/Dependencies.cmake
@@ -51,7 +51,7 @@ if(MYGUI_RENDERSYSTEM EQUAL 3)
 	find_package(ZLIB)
 	find_package(OGRE_Old)
 	macro_log_feature(OGRE_FOUND "ogre" "Support for the Ogre render system" "" TRUE "" "")
-elseif(MYGUI_RENDERSYSTEM EQUAL 4 OR MYGUI_RENDERSYSTEM EQUAL 7)
+elseif(MYGUI_RENDERSYSTEM EQUAL 4 OR MYGUI_RENDERSYSTEM EQUAL 7 OR MYGUI_RENDERSYSTEM EQUAL 8)
 	find_package(SDL2_image)
 	if(POLICY CMP0072)
 		cmake_policy(SET CMP0072 OLD)
