--- tools/qmlimportscanner/qmlimportscanner.pro.orig	2019-12-31 21:19:52 UTC
+++ tools/qmlimportscanner/qmlimportscanner.pro
@@ -47,7 +47,7 @@ cmake_config_file.output = $$MODULE_BASE_OUTDIR/lib/cm
 QMAKE_SUBSTITUTES += cmake_config_file
 
 cmake_build_integration.files = $$cmake_config_file.output $$PWD/Qt5QmlImportScannerTemplate.cpp.in
-cmake_build_integration.path = $$[QT_INSTALL_LIBS]/cmake/Qt5QmlImportScanner
+cmake_build_integration.path = $$[QT_INSTALL_PREFIX]/lib/cmake/Qt5QmlImportScanner
 prefix_build: INSTALLS += cmake_build_integration
 else: COPIES += cmake_build_integration
 
