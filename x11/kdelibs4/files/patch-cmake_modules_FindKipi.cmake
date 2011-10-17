--- cmake/modules/FindKipi.cmake.orig	2011-05-20 22:24:53.000000000 +0200
+++ cmake/modules/FindKipi.cmake	2011-07-31 04:14:21.939197375 +0200
@@ -62,52 +62,26 @@
 
       # use pkg-config to get the directories and then use these values
       # in the FIND_PATH() and FIND_LIBRARY() calls
-      include(UsePkgConfig)
-
-      PKGCONFIG(libkipi _KIPIIncDir _KIPILinkDir _KIPILinkFlags _KIPICflags)
-
-      if (_KIPILinkFlags)
-        # query pkg-config asking for a libkipi >= 0.2.0
-        exec_program(${PKGCONFIG_EXECUTABLE} ARGS --atleast-version=0.2.0 libkipi RETURN_VALUE _return_VALUE OUTPUT_VARIABLE _pkgconfigDevNull )
-        if (_return_VALUE STREQUAL "0")
-            message(STATUS "Found libkipi release >= 0.2.0")
-            set(KIPI_VERSION_GOOD_FOUND TRUE)
-        else (_return_VALUE STREQUAL "0")
-            message(STATUS "Found libkipi release < 0.2.0, too old")
-            set(KIPI_VERSION_GOOD_FOUND FALSE)
-            set(KIPI_FOUND FALSE)
-        endif (_return_VALUE STREQUAL "0")
-      else (_KIPILinkFlags)
-        set(KIPI_VERSION_GOOD_FOUND FALSE)
-        set(KIPI_FOUND FALSE)
-      endif (_KIPILinkFlags)
-    else (NOT WIN32)
-      set(KIPI_VERSION_GOOD_FOUND TRUE)
+      include(FindPkgConfig)
+      pkg_check_modules(PC_LIBKIPI libkipi-kde4>=0.2.0)
+      set(KIPI_DEFINITIONS ${PC_LIBKIPI_CFLAGS_OTHER})
     endif (NOT WIN32)
-    if (KIPI_VERSION_GOOD_FOUND)
-        set(KIPI_DEFINITIONS ${_KIPICflags})
-
-        find_path(KIPI_INCLUDE_DIR NAMES libkipi/version.h PATHS ${KDE4_INCLUDE_DIR} ${_KIPIIncDir})
-        find_library(KIPI_LIBRARIES NAMES kipi PATHS ${KDE4_LIB_DIR} ${_KIPILinkDir})
-
-        if (KIPI_INCLUDE_DIR AND KIPI_LIBRARIES)
-            set(KIPI_FOUND TRUE)
-        endif (KIPI_INCLUDE_DIR AND KIPI_LIBRARIES)
-      endif (KIPI_VERSION_GOOD_FOUND)
-      if (KIPI_FOUND)
-          if (NOT Kipi_FIND_QUIETLY)
-              message(STATUS "Found libkipi: ${KIPI_LIBRARIES}")
-          endif (NOT Kipi_FIND_QUIETLY)
-      else (KIPI_FOUND)
-          if (Kipi_FIND_REQUIRED)
-              if (NOT KIPI_INCLUDE_DIR)
-                  message(FATAL_ERROR "Could NOT find libkipi header files")
-              endif (NOT KIPI_INCLUDE_DIR)
-              if (NOT KIPI_LIBRARIES)
-                  message(FATAL_ERROR "Could NOT find libkipi library")
-              endif (NOT KIPI_LIBRARIES)
-          endif (Kipi_FIND_REQUIRED)
-      endif (KIPI_FOUND)
+    find_path(KIPI_INCLUDE_DIR NAMES libkipi/version.h
+        HINTS
+        ${PC_LIBKIPI_INCLUDEDIR}
+        ${PC_LIBKIPI_INCLUDE_DIRS}
+        )
+    find_library(KIPI_LIBRARY NAMES kipi
+        HINTS
+        ${PC_LIBKIPI_LIBDIR}
+        ${PC_LIBKIPI_LIBRARY_DIRS}
+        )
+
+    include(FindPackageHandleStandardArgs)
+    find_package_handle_standard_args(Kipi DEFAULT_MSG KIPI_LIBRARY KIPI_INCLUDE_DIR)
+    if(KIPI_FOUND)
+       set(KIPI_LIBRARIES ${KIPI_LIBRARY})
+    endif(KIPI_FOUND)
 
     mark_as_advanced(KIPI_INCLUDE_DIR KIPI_LIBRARIES KIPI_DEFINITIONS)
 
