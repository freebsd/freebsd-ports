--- cmake/modules/PythonMacros.cmake.orig	2013-01-23 22:44:16.000000000 +0100
+++ cmake/modules/PythonMacros.cmake	2013-02-27 13:39:48.000000000 +0100
@@ -43,9 +43,11 @@
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
 
@@ -60,6 +62,7 @@
         TARGET compile_python_files
         COMMAND "${CMAKE_COMMAND}" -E echo "${_message}"
         COMMAND "${PYTHON_EXECUTABLE}" "${_python_compile_py}" "${_bin_py}"
+        COMMAND "${PYTHON_EXECUTABLE}" -O "${_python_compile_py}" "${_bin_py}"
         DEPENDS "${_absfilename}"
       )
     else()
@@ -68,11 +71,13 @@
         COMMAND "${CMAKE_COMMAND}" -E echo "${_message}"
         COMMAND "${CMAKE_COMMAND}" -E copy "${_absfilename}" "${_bin_py}"
         COMMAND "${PYTHON_EXECUTABLE}" "${_python_compile_py}" "${_bin_py}"
+        COMMAND "${PYTHON_EXECUTABLE}" -O "${_python_compile_py}" "${_bin_py}"
         DEPENDS "${_absfilename}"
       )
     endif()
 
     install(FILES ${_bin_pyc} DESTINATION "${_py_install_dir}")
+    install(FILES ${_bin_pyo} DESTINATION "${_py_install_dir}")
     unset(_py_install_dir)
     unset(_message)
 
