Do the same thing we do in devel/cmake's FindQt4.cmake patch. The idea behind
the change is that the directories FindQt4.cmake looks for might not be
present at the time CMake looks for them since the ports that actually create
them may not be required by the port calling CMake.
--- cmake/modules/FindQt4.cmake.orig	2014-11-06 22:33:50 UTC
+++ cmake/modules/FindQt4.cmake
@@ -638,23 +638,12 @@ IF (QT4_QMAKE_FOUND)
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
