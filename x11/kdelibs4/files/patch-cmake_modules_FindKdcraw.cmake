--- ./cmake/modules/FindKdcraw.cmake.orig	2009-05-08 02:16:53.000000000 +0400
+++ ./cmake/modules/FindKdcraw.cmake	2009-09-23 00:36:17.000000000 +0400
@@ -45,63 +45,33 @@
 
   else(KDCRAW_LOCAL_FOUND)
 
-    message(STATUS "Check Kdcraw library using pkg-config...")
     if(NOT WIN32)
+      message(STATUS "Check Kdcraw library using pkg-config...")
+
       # use pkg-config to get the directories and then use these values
       # in the FIND_PATH() and FIND_LIBRARY() calls
-      INCLUDE(UsePkgConfig)
-    
-      PKGCONFIG(libkdcraw _KDCRAWIncDir _KDCRAWLinkDir _KDCRAWLinkFlags _KDCRAWCflags)
-    
-      if(_KDCRAWLinkFlags)
-        # query pkg-config asking for a libkdcraw >= 0.2.0
-        EXEC_PROGRAM(${PKGCONFIG_EXECUTABLE} ARGS --atleast-version=0.2.0 libkdcraw RETURN_VALUE _return_VALUE OUTPUT_VARIABLE _pkgconfigDevNull )
-        if(_return_VALUE STREQUAL "0")
-            message(STATUS "Found libkdcraw release >= 0.2.0")
-            set(KDCRAW_VERSION_GOOD_FOUND TRUE)
-        else(_return_VALUE STREQUAL "0")
-            message(STATUS "Found libkdcaw release < 0.2.0, too old")
-            set(KDCRAW_VERSION_GOOD_FOUND FALSE)
-            set(KDCRAW_FOUND FALSE)
-        endif(_return_VALUE STREQUAL "0")
-      else(_KDCRAWLinkFlags)
-        set(KDCRAW_VERSION_GOOD_FOUND FALSE)
-        set(KDCRAW_FOUND FALSE)
-      endif(_KDCRAWLinkFlags)
-    ELSE(NOT WIN32)
-      set(KDCRAW_VERSION_GOOD_FOUND TRUE)
-    ENDif(NOT WIN32)
+      include(FindPkgConfig)
+      pkg_check_modules(PC_LIBKDCRAW libkdcraw-kde4>=0.2.0)
+      set(KDCRAW_DEFINITIONS ${PC_LIBKDCRAW_CFLAGS_OTHER})
+    endif(NOT WIN32)
 
-    if(KDCRAW_VERSION_GOOD_FOUND)
-        set(KDCRAW_DEFINITIONS "${_KDCRAWCflags}")
-    
-        FIND_PATH(KDCRAW_INCLUDE_DIR libkdcraw/version.h
-        ${_KDCRAWIncDir}
+    find_path(KDCRAW_INCLUDE_DIR NAMES libkdcraw/version.h
+        HINTS
+        ${PC_LIBKDCRAW_INCLUDEDIR}
+        ${PC_LIBKDCRAW_INCLUDE_DIRS}
         )
-    
-        FIND_LIBRARY(KDCRAW_LIBRARIES NAMES kdcraw
-        PATHS
-        ${_KDCRAWLinkDir}
+    find_library(KDCRAW_LIBRARY NAMES kdcraw
+        HINTS
+        ${PC_LIBKDCRAW_LIBDIR}
+        ${PC_LIBKDCRAW_LIBRARY_DIRS}
         )
-    
-        if (KDCRAW_INCLUDE_DIR AND KDCRAW_LIBRARIES)
-            set(KDCRAW_FOUND TRUE)
-        endif (KDCRAW_INCLUDE_DIR AND KDCRAW_LIBRARIES)
-     endif(KDCRAW_VERSION_GOOD_FOUND) 
-     if (KDCRAW_FOUND)
-         if (NOT Kdcraw_FIND_QUIETLY)
-             message(STATUS "Found libkdcraw: ${KDCRAW_LIBRARIES}")
-         endif (NOT Kdcraw_FIND_QUIETLY)
-     else (KDCRAW_FOUND)
-         if (Kdcraw_FIND_REQUIRED)
-             if (NOT KDCRAW_INCLUDE_DIR)
-                 message(FATAL_ERROR "Could NOT find libkdcraw header files")
-             endif (NOT KDCRAW_INCLUDE_DIR)
-             if (NOT KDCRAW_LIBRARIES)
-                 message(FATAL_ERROR "Could NOT find libkdcraw library")
-             endif (NOT KDCRAW_LIBRARIES)
-         endif (Kdcraw_FIND_REQUIRED)
-     endif (KDCRAW_FOUND)
+
+    include(FindPackageHandleStandardArgs)
+    find_package_handle_standard_args(Kdcraw DEFAULT_MSG KDCRAW_LIBRARY KDCRAW_INCLUDE_DIR)
+
+    if(KDCRAW_FOUND)
+       set(KDCRAW_LIBRARIES ${KDCRAW_LIBRARY})
+    endif(KDCRAW_FOUND)
     
     MARK_AS_ADVANCED(KDCRAW_INCLUDE_DIR KDCRAW_LIBRARIES)
 
