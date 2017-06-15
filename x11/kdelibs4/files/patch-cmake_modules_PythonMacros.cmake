The pyo-related changes are (at least for now) FreeBSD-specific and are present
in order to install .pyo files in addition to .pyc files when installing Python
modules.
--- cmake/modules/PythonMacros.cmake
+++ cmake/modules/PythonMacros.cmake
@@ -41,16 +41,18 @@ macro(PYTHON_INSTALL SOURCE_FILE DESTINATION_DIR)
     if(PYTHON_VERSION_STRING VERSION_GREATER 3.1)
       # To get the right version for suffix
       set(_bin_pyc "${CMAKE_CURRENT_BINARY_DIR}/${_basepath}/__pycache__/${_filenamebase}.cpython-${PYTHON_VERSION_MAJOR}${PYTHON_VERSION_MINOR}.pyc")
+      set(_bin_pyo "${CMAKE_CURRENT_BINARY_DIR}/${_basepath}/__pycache__/${_filenamebase}.cpython-${PYTHON_VERSION_MAJOR}${PYTHON_VERSION_MINOR}.pyo")
       set(_py_install_dir "${DESTINATION_DIR}/__pycache__/")
     else()
       set(_bin_pyc "${CMAKE_CURRENT_BINARY_DIR}/${_basepath}/${_filenamebase}.pyc")
+      set(_bin_pyo "${CMAKE_CURRENT_BINARY_DIR}/${_basepath}/${_filenamebase}.pyo")
       set(_py_install_dir "${DESTINATION_DIR}")
     endif()
 
     file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${_basepath})
 
     # Setting because it will be displayed later, in compile_python_files
-    set(_message "Byte-compiling ${_bin_py} to ${_bin_pyc}")
+    set(_message "Byte-compiling ${_bin_py} to ${_bin_pyc} and ${_bin_pyo}")
 
     string(REPLACE "/" "_" _rule_name "${_basepath}/${_bin_pyc}")
     add_custom_target("${_rule_name}" ALL)
@@ -61,6 +63,7 @@ macro(PYTHON_INSTALL SOURCE_FILE DESTINATION_DIR)
         TARGET "${_rule_name}"
         COMMAND "${CMAKE_COMMAND}" -E echo "${_message}"
         COMMAND "${PYTHON_EXECUTABLE}" "${_python_compile_py}" "--destination-dir" "${DESTINATION_DIR}" "${_bin_py}"
+        COMMAND "${PYTHON_EXECUTABLE}" -O "${_python_compile_py}" "--destination-dir" "${DESTINATION_DIR}" "${_bin_py}"
         DEPENDS "${_absfilename}"
       )
     else()
@@ -69,11 +72,12 @@ macro(PYTHON_INSTALL SOURCE_FILE DESTINATION_DIR)
         COMMAND "${CMAKE_COMMAND}" -E echo "${_message}"
         COMMAND "${CMAKE_COMMAND}" -E copy "${_absfilename}" "${_bin_py}"
         COMMAND "${PYTHON_EXECUTABLE}" "${_python_compile_py}" "--destination-dir" "${DESTINATION_DIR}" "${_bin_py}"
+        COMMAND "${PYTHON_EXECUTABLE}" -O "${_python_compile_py}" "--destination-dir" "${DESTINATION_DIR}" "${_bin_py}"
         DEPENDS "${_absfilename}"
       )
     endif()
 
-    install(FILES ${_bin_pyc} DESTINATION "${_py_install_dir}")
+    install(FILES ${_bin_pyc} ${_bin_pyo} DESTINATION "${_py_install_dir}")
     unset(_py_install_dir)
     unset(_message)
 
