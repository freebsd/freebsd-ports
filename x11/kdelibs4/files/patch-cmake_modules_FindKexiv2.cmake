--- cmake/modules/FindKexiv2.cmake.orig	2011-05-20 22:24:53.000000000 +0200
+++ cmake/modules/FindKexiv2.cmake	2011-07-31 04:11:37.659261791 +0200
@@ -62,59 +62,28 @@
 
       # use pkg-config to get the directories and then use these values
       # in the FIND_PATH() and FIND_LIBRARY() calls
-      include(UsePkgConfig)
-    
-      PKGCONFIG(libkexiv2 _KEXIV2IncDir _KEXIV2LinkDir _KEXIV2LinkFlags _KEXIV2Cflags)
-    
-      if(_KEXIV2LinkFlags)
-        # query pkg-config asking for a libkexiv2 >= 0.2.0
-        exec_program(${PKGCONFIG_EXECUTABLE} ARGS --atleast-version=0.2.0 libkexiv2 RETURN_VALUE _return_VALUE OUTPUT_VARIABLE _pkgconfigDevNull )
-        if(_return_VALUE STREQUAL "0")
-            message(STATUS "Found libkexiv2 release >= 0.2.0")
-            set(KEXIV2_VERSION_GOOD_FOUND TRUE)
-        else(_return_VALUE STREQUAL "0")
-            message(STATUS "Found libkexiv2 release < 0.2.0, too old")
-            set(KEXIV2_VERSION_GOOD_FOUND FALSE)
-            set(KEXIV2_FOUND FALSE)
-        endif(_return_VALUE STREQUAL "0")
-      else(_KEXIV2LinkFlags)
-        set(KEXIV2_VERSION_GOOD_FOUND FALSE)
-        set(KEXIV2_FOUND FALSE)
-      endif(_KEXIV2LinkFlags)
-    else(NOT WIN32)
-      set(KEXIV2_VERSION_GOOD_FOUND TRUE)
+      include(FindPkgConfig)
+      pkg_check_modules(PC_LIBKEXIV2 libkexiv2-kde4>=0.2.0)
+      set(KEXIV2_DEFINITIONS ${PC_LIBKEXIV2_CFLAGS_OTHER})
     endif(NOT WIN32)
 
-    if(KEXIV2_VERSION_GOOD_FOUND)
-        set(KEXIV2_DEFINITIONS "${_KEXIV2Cflags}")
-    
-        find_path(KEXIV2_INCLUDE_DIR libkexiv2/version.h
-        ${_KEXIV2IncDir}
+    find_path(KEXIV2_INCLUDE_DIR NAMES libkexiv2/version.h
+        HINTS
+        ${PC_LIBKEXIV2_INCLUDEDIR}
+        ${PC_LIBKEXIV2_INCLUDE_DIRS}
         )
     
-        find_library(KEXIV2_LIBRARIES NAMES kexiv2
-        PATHS
-        ${_KEXIV2LinkDir}
+    find_library(KEXIV2_LIBRARY NAMES kexiv2
+        HINTS
+        ${PC_LIBKEXIV2_LIBDIR}
+        ${PC_LIBKEXIV2_LIBRARY_DIRS}
         )
     
-        if (KEXIV2_INCLUDE_DIR AND KEXIV2_LIBRARIES)
-            set(KEXIV2_FOUND TRUE)
-        endif (KEXIV2_INCLUDE_DIR AND KEXIV2_LIBRARIES)
-      endif(KEXIV2_VERSION_GOOD_FOUND) 
-      if (KEXIV2_FOUND)
-          if (NOT Kexiv2_FIND_QUIETLY)
-              message(STATUS "Found libkexiv2: ${KEXIV2_LIBRARIES}")
-          endif (NOT Kexiv2_FIND_QUIETLY)
-      else (KEXIV2_FOUND)
-          if (Kexiv2_FIND_REQUIRED)
-              if (NOT KEXIV2_INCLUDE_DIR)
-                  message(FATAL_ERROR "Could NOT find libkexiv2 header files")
-              endif (NOT KEXIV2_INCLUDE_DIR)
-              if (NOT KEXIV2_LIBRARIES)
-                  message(FATAL_ERROR "Could NOT find libkexiv2 library")
-              endif (NOT KEXIV2_LIBRARIES)
-          endif (Kexiv2_FIND_REQUIRED)
-      endif (KEXIV2_FOUND)
+    include(FindPackageHandleStandardArgs)
+    find_package_handle_standard_args(Kexiv2 DEFAULT_MSG KEXIV2_LIBRARY KEXIV2_INCLUDE_DIR)
+    if(KEXIV2_FOUND)
+       set(KEXIV2_LIBRARIES ${KEXIV2_LIBRARY})
+    endif(KEXIV2_FOUND)
     
     mark_as_advanced(KEXIV2_INCLUDE_DIR KEXIV2_LIBRARIES KEXIV2_DEFINITIONS)
 
