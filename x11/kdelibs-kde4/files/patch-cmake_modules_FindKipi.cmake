--- cmake/modules/FindKipi.cmake.orig	2013-03-09 04:00:37.000000000 +0000
+++ cmake/modules/FindKipi.cmake	2013-03-11 16:15:53.867922813 +0000
@@ -78,7 +78,7 @@
       ENDIF(NOT Kipi_FIND_QUIETLY)
 
       INCLUDE(FindPkgConfig)
-      PKG_CHECK_MODULES(PC_KIPI libkipi>=${Kipi_FIND_VERSION})
+      PKG_CHECK_MODULES(PC_KIPI libkipi-kde4>=${Kipi_FIND_VERSION})
     ENDIF(NOT WIN32)
 
     FIND_LIBRARY(KIPI_LIBRARIES NAMES kipi HINTS ${PC_KIPI_LIBRARY_DIRS} ${LIB_INSTALL_DIR} ${KDE4_LIB_DIR})
