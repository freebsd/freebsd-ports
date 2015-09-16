Hunks 1 and 3:
  Backport upstream CMake change de30173d ("Remove C compiler requirement from
  FindQt4.cmake") so that it uses a C++ compiler to look for Q_WS_X11,
  otherwise the build fails because <ciso646> from qglobal.h is not present
  when using a C compiler.

Hunk 2:
  Do the same thing we do in devel/cmake's FindQt4.cmake patch. The idea behind
  the change is that the directories FindQt4.cmake looks for might not be
  present at the time CMake looks for them since the ports that actually create
  them may not be required by the port calling CMake.
--- cmake/modules/FindQt4.cmake.orig	2014-11-06 22:33:50 UTC
+++ cmake/modules/FindQt4.cmake
@@ -405,7 +405,7 @@ QT_CHECK_FLAG_EXISTS(-DQT_NO_DEBUG CMAKE
 QT_CHECK_FLAG_EXISTS(-DQT_NO_DEBUG CMAKE_CXX_FLAGS_MINSIZEREL "release minsize")
 
 INCLUDE(MacroPushRequiredVars)
-INCLUDE(CheckSymbolExists)
+INCLUDE(CheckCXXSymbolExists)
 INCLUDE(MacroAddFileDependencies)
 
 SET(QT_USE_FILE ${CMAKE_ROOT}/Modules/UseQt4.cmake)
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
@@ -671,19 +660,19 @@ IF (QT4_QMAKE_FOUND)
     SET(CMAKE_REQUIRED_FLAGS "-F${QT_LIBRARY_DIR} ")
   ENDIF( QT_USE_FRAMEWORKS )
   # Check for Window system symbols (note: only one should end up being set)
-  CHECK_SYMBOL_EXISTS(Q_WS_X11 "QtCore/qglobal.h" Q_WS_X11)
-  CHECK_SYMBOL_EXISTS(Q_WS_WIN "QtCore/qglobal.h" Q_WS_WIN)
-  CHECK_SYMBOL_EXISTS(Q_WS_QWS "QtCore/qglobal.h" Q_WS_QWS)
-  CHECK_SYMBOL_EXISTS(Q_WS_MAC "QtCore/qglobal.h" Q_WS_MAC)
+  CHECK_CXX_SYMBOL_EXISTS(Q_WS_X11 "QtCore/qglobal.h" Q_WS_X11)
+  CHECK_CXX_SYMBOL_EXISTS(Q_WS_WIN "QtCore/qglobal.h" Q_WS_WIN)
+  CHECK_CXX_SYMBOL_EXISTS(Q_WS_QWS "QtCore/qglobal.h" Q_WS_QWS)
+  CHECK_CXX_SYMBOL_EXISTS(Q_WS_MAC "QtCore/qglobal.h" Q_WS_MAC)
   IF(Q_WS_MAC)
     IF(QT_QMAKE_CHANGED)
       UNSET(QT_MAC_USE_COCOA CACHE)
     ENDIF(QT_QMAKE_CHANGED)
-    CHECK_SYMBOL_EXISTS(QT_MAC_USE_COCOA "QtCore/qconfig.h" QT_MAC_USE_COCOA)
+    CHECK_CXX_SYMBOL_EXISTS(QT_MAC_USE_COCOA "QtCore/qconfig.h" QT_MAC_USE_COCOA)
   ENDIF(Q_WS_MAC)
 
   IF (QT_QTCOPY_REQUIRED)
-     CHECK_SYMBOL_EXISTS(QT_IS_QTCOPY "QtCore/qglobal.h" QT_KDE_QT_COPY)
+     CHECK_CXX_SYMBOL_EXISTS(QT_IS_QTCOPY "QtCore/qglobal.h" QT_KDE_QT_COPY)
      IF (NOT QT_IS_QTCOPY)
         MESSAGE(FATAL_ERROR "qt-copy is required, but hasn't been found")
      ENDIF (NOT QT_IS_QTCOPY)
