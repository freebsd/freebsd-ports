--- tools/qmlcachegen/qmlcachegen.pro.orig	2018-10-01 23:20:01 UTC
+++ tools/qmlcachegen/qmlcachegen.pro
@@ -29,7 +29,7 @@ cmake_config_file.output = $$MODULE_BASE_OUTDIR/lib/cm
 QMAKE_SUBSTITUTES += cmake_config_file
 
 cmake_build_integration.files = $$cmake_config_file.output
-cmake_build_integration.path = $$[QT_INSTALL_LIBS]/cmake/Qt5QuickCompiler
+cmake_build_integration.path = $$[QT_INSTALL_PREFIX]/lib/cmake/Qt5QuickCompiler
 prefix_build: INSTALLS += cmake_build_integration
 else: COPIES += cmake_build_integration
 
