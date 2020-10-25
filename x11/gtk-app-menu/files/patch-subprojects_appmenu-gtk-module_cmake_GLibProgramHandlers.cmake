--- subprojects/appmenu-gtk-module/cmake/GLibProgramHandlers.cmake.orig	2019-07-29 14:45:42 UTC
+++ subprojects/appmenu-gtk-module/cmake/GLibProgramHandlers.cmake
@@ -27,10 +27,10 @@ macro(add_schema SCHEMA_NAME)
     message (STATUS "GSettings schemas will be installed into ${GSETTINGS_PREFIX}/${GSETTINGS_DIR}")
     install (FILES ${CMAKE_CURRENT_SOURCE_DIR}/${SCHEMA_NAME} DESTINATION ${GSETTINGS_PREFIX}/${GSETTINGS_DIR} COMPONENT ${ARGV1} OPTIONAL)
 
-    if (GSETTINGS_COMPILE)
-        install (CODE "message (STATUS \"Compiling GSettings schemas\")")
-        install (CODE "execute_process (COMMAND ${GLIB2_COMPILE_SCHEMAS_EXECUTABLE} ${GSETTINGS_PREFIX}/${GSETTINGS_DIR})")
-    endif ()
+    # if (GSETTINGS_COMPILE)
+        # install (CODE "message (STATUS \"Compiling GSettings schemas\")")
+        # install (CODE "execute_process (COMMAND ${GLIB2_COMPILE_SCHEMAS_EXECUTABLE} ${GSETTINGS_PREFIX}/${GSETTINGS_DIR})")
+    # endif ()
 endmacro()
 
 macro(add_glib_marshal outsources outincludes name prefix)
