--- tools/qmlcachegen/qmlcachegen.pro.orig	2018-06-22 17:15:33 UTC
+++ tools/qmlcachegen/qmlcachegen.pro
@@ -15,7 +15,7 @@ prefix_build: INSTALLS += build_integration
 else: COPIES += build_integration
 
 cmake_build_integration.files = Qt5QuickCompilerConfig.cmake
-cmake_build_integration.path = $$[QT_INSTALL_LIBS]/cmake/Qt5QuickCompiler
+cmake_build_integration.path = $$[QT_INSTALL_PREFIX]/lib/cmake/Qt5QuickCompiler
 prefix_build: INSTALLS += cmake_build_integration
 else: COPIES += cmake_build_integration
 
