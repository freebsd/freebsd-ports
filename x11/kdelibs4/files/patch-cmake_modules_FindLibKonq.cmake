--- ./cmake/modules/FindLibKonq.cmake.orig	2009-05-27 21:54:40.000000000 +0200
+++ ./cmake/modules/FindLibKonq.cmake	2009-06-06 01:53:49.000000000 +0200
@@ -14,7 +14,7 @@
 
 find_path(LIBKONQ_INCLUDE_DIR konq_popupmenuplugin.h )
 
-find_library(LIBKONQ_LIBRARY konq)
+find_library(LIBKONQ_LIBRARY NAMES konq PATHS ${KDE4_LIB_INSTALL_DIR} NO_DEFAULT_PATH)
 
 include(FindPackageHandleStandardArgs)
 find_package_handle_standard_args(LIBKONQ  DEFAULT_MSG  LIBKONQ_INCLUDE_DIR LIBKONQ_LIBRARY )
