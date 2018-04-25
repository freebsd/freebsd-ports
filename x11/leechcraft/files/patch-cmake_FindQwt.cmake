--- cmake/FindQwt.cmake.orig	2018-03-09 18:41:44 UTC
+++ cmake/FindQwt.cmake
@@ -6,6 +6,7 @@
 find_path (QWT_INCLUDE_DIRS
 	NAMES qwt_plot.h
 	PATHS
+	%%QT_INCDIR%%/qwt6
 	/usr/local/include/qwt-qt4
 	/usr/local/include/qwt6
 	/usr/local/include/qwt
@@ -18,6 +19,7 @@ find_path (QWT_INCLUDE_DIRS
 find_library (QWT_LIBRARIES
 	NAMES qwt-qt4 qwt6 qwt
 	PATHS
+	%%QT_LIBDIR%%
 	/usr/local/lib
 	/usr/lib
 	/usr/local/lib/qwt.framework
