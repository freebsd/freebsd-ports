Includes the following two upstream commits:

commit c828f8592fcfd6c2a66ebc18a826de38d6a2fef2
Author: Pino Toscano <pino@kde.org>
Date:   Sat Dec 31 12:08:59 2016 +0100

    cmake: look for hunspell-1.6 as well

commit 2ab2745eb01f73355c490ac8d5d1837dec84fd6c
Author: Wolfgang Bauer <wbauer@tmo.at>
Date:   Thu Oct 20 15:51:29 2016 +0200

    Support newer hunspell versions in FindHUNSPELL.cmake

    REVIEW: 128600

--- cmake/modules/FindHUNSPELL.cmake
+++ cmake/modules/FindHUNSPELL.cmake
@@ -14,7 +14,7 @@ ENDIF (HUNSPELL_INCLUDE_DIR AND HUNSPELL_LIBRARIES)
 
 FIND_PATH(HUNSPELL_INCLUDE_DIR hunspell/hunspell.hxx )
 
-FIND_LIBRARY(HUNSPELL_LIBRARIES NAMES hunspell-1.3 hunspell-1.2)
+FIND_LIBRARY(HUNSPELL_LIBRARIES NAMES hunspell-2.0 hunspell-1.6 hunspell-1.5 hunspell-1.4 hunspell-1.3 hunspell-1.2)
 
 # handle the QUIETLY and REQUIRED arguments and set HUNSPELL_FOUND to TRUE if 
 # all listed variables are TRUE
