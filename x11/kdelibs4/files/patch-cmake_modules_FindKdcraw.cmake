--- cmake/modules/FindKdcraw.cmake.orig	2013-03-09 04:00:37.000000000 +0000
+++ cmake/modules/FindKdcraw.cmake	2013-03-11 16:15:36.354922501 +0000
@@ -77,7 +77,7 @@
       # in the find_path() and find_library() calls
       include(FindPkgConfig)
 
-      pkg_check_modules(PC_KDCRAW libkdcraw)
+      pkg_check_modules(PC_KDCRAW libkdcraw-kde4)
 
       if (PC_KDCRAW_FOUND)
         # make sure the version is >= 0.2.0
