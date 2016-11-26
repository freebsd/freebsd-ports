--- cmake/modules/FindHUNSPELL.cmake.orig	2015-06-26 03:14:18 UTC
+++ cmake/modules/FindHUNSPELL.cmake
@@ -14,7 +14,7 @@ ENDIF (HUNSPELL_INCLUDE_DIR AND HUNSPELL
 
 FIND_PATH(HUNSPELL_INCLUDE_DIR hunspell/hunspell.hxx )
 
-FIND_LIBRARY(HUNSPELL_LIBRARIES NAMES hunspell-1.3 hunspell-1.2)
+FIND_LIBRARY(HUNSPELL_LIBRARIES NAMES hunspell-1.5 hunspell-1.4 hunspell-1.3 hunspell-1.2)
 
 # handle the QUIETLY and REQUIRED arguments and set HUNSPELL_FOUND to TRUE if 
 # all listed variables are TRUE
