--- ../cmake/modules/FindLibKonq.cmake.orig	2009-01-07 03:13:55.000000000 +0300
+++ ../cmake/modules/FindLibKonq.cmake	2009-03-06 22:06:02.000000000 +0300
@@ -19,7 +19,7 @@
 else(LIBKONQ_INCLUDE_DIR AND LIBKONQ_LIBRARY)
   find_path(LIBKONQ_INCLUDE_DIR konq_popupmenuplugin.h )
 
-  find_library(LIBKONQ_LIBRARY konq)
+  find_library(LIBKONQ_LIBRARY NAMES konq PATHS ${KDE4_LIB_INSTALL_DIR} NO_DEFAULT_PATH)
 
   if(LIBKONQ_INCLUDE_DIR AND LIBKONQ_LIBRARY)
     set(LIBKONQ_FOUND TRUE)
