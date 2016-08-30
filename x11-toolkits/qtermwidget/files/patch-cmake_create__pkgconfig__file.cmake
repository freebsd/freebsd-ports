--- cmake/create_pkgconfig_file.cmake.orig	2014-10-21 15:47:40 UTC
+++ cmake/create_pkgconfig_file.cmake
@@ -25,5 +25,6 @@ macro (create_pkgconfig_file name desc r
             "\n"
         )
 
-    install(FILES ${_pkgfname} DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)
+    # Use libdata rather than CMAKE_INSTALL_LIBDIR for pkgconfig on FreeBSD
+    install(FILES ${_pkgfname} DESTINATION libdata/pkgconfig)
 endmacro()
