--- ./cmake/modules/FindQt4.cmake.orig	2011-07-28 05:34:31.000000000 +1100
+++ ./cmake/modules/FindQt4.cmake	2012-05-18 00:28:12.000000000 +1100
@@ -627,23 +627,12 @@
   # ask qmake for the imports directory
   IF (QT_LIBRARY_DIR AND NOT QT_IMPORTS_DIR OR QT_QMAKE_CHANGED)
     _qt4_query_qmake(QT_INSTALL_IMPORTS qt_imports_dir)
-    if(qt_imports_dir)
-      SET(QT_IMPORTS_DIR NOTFOUND)
-      foreach(qt_cross_path ${CMAKE_FIND_ROOT_PATH})
-        set(qt_cross_paths ${qt_cross_paths} "${qt_cross_path}/imports")
-      endforeach(qt_cross_path)
-      FIND_PATH(QT_IMPORTS_DIR NAMES Qt
-        HINTS ${qt_cross_paths} ${qt_imports_dir}
-        DOC "The location of the Qt imports"
-        NO_CMAKE_PATH NO_CMAKE_ENVIRONMENT_PATH NO_SYSTEM_ENVIRONMENT_PATH
-        NO_CMAKE_SYSTEM_PATH)
-      mark_as_advanced(QT_IMPORTS_DIR)
-    endif(qt_imports_dir)
+    SET(QT_IMPORTS_DIR ${qt_imports_dir} CACHE PATH "The location of the Qt imports" FORCE)
   ENDIF (QT_LIBRARY_DIR AND NOT QT_IMPORTS_DIR  OR  QT_QMAKE_CHANGED)
 
   # Make variables changeble to the advanced user
   MARK_AS_ADVANCED( QT_LIBRARY_DIR QT_DOC_DIR QT_MKSPECS_DIR
-                    QT_PLUGINS_DIR QT_TRANSLATIONS_DIR)
+                    QT_PLUGINS_DIR QT_TRANSLATIONS_DIR QT_IMPORTS_DIR)
 
 
   #############################################
