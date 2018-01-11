--- cmake/03-libs.cmake.orig	2017-12-03 17:03:49 UTC
+++ cmake/03-libs.cmake
@@ -21,3 +21,8 @@ querylib(WITH_XRENDER "pkg-config" xcb-render libs dir
 querylib(WITH_XRM "pkg-config" xcb-xrm libs dirs)
 querylib(WITH_XSYNC "pkg-config" xcb-sync libs dirs)
 querylib(WITH_XCURSOR "pkg-config" xcb-cursor libs dirs)
+
+# FreeBSD Support
+if(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+  querylib(TRUE "pkg-config" libinotify libs dirs)
+endif()
