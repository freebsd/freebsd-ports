--- ./cmake/modules/PythonMacros.cmake.orig	2012-11-30 07:17:39.000000000 +0000
+++ ./cmake/modules/PythonMacros.cmake	2013-01-03 16:30:53.706219657 +0000
@@ -41,8 +41,10 @@
         # To get the right version for suffix
         STRING(REPLACE "." "" _suffix ${PYTHON_SHORT_VERSION})
         SET(_bin_pyc ${CMAKE_CURRENT_BINARY_DIR}/${_basepath}/__pycache__/${_filenamebase}.cpython-${_suffix}.pyc)
+        SET(_bin_pyo ${CMAKE_CURRENT_BINARY_DIR}/${_basepath}/__pycache__/${_filenamebase}.cpython-${_suffix}.pyo)
     ELSE(PYTHON_SHORT_VERSION GREATER 3.1)
         SET(_bin_pyc ${CMAKE_CURRENT_BINARY_DIR}/${_basepath}/${_filenamebase}.pyc)
+        SET(_bin_pyo ${CMAKE_CURRENT_BINARY_DIR}/${_basepath}/${_filenamebase}.pyo)
     ENDIF(PYTHON_SHORT_VERSION GREATER 3.1)
 
     FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${_basepath})
@@ -55,6 +57,7 @@
         TARGET compile_python_files
         COMMAND ${CMAKE_COMMAND} -E echo ${_message}
         COMMAND ${PYTHON_EXECUTABLE} ${_python_compile_py} ${_bin_py}
+        COMMAND ${PYTHON_EXECUTABLE} -O ${_python_compile_py} ${_bin_py}
         DEPENDS ${_absfilename}
         )
     ELSE(_abs_bin_py STREQUAL ${_absfilename})
@@ -63,14 +66,15 @@
         COMMAND ${CMAKE_COMMAND} -E echo ${_message} 
         COMMAND ${CMAKE_COMMAND} -E copy ${_absfilename} ${_bin_py}
         COMMAND ${PYTHON_EXECUTABLE} ${_python_compile_py} ${_bin_py}
+        COMMAND ${PYTHON_EXECUTABLE} -O ${_python_compile_py} ${_bin_py}
         DEPENDS ${_absfilename}
         )
     ENDIF(_abs_bin_py STREQUAL ${_absfilename})
 
     IF(PYTHON_SHORT_VERSION GREATER 3.1)
-        INSTALL(FILES ${_bin_pyc} DESTINATION ${DESTINATION_DIR}/__pycache__/)
+        INSTALL(FILES ${_bin_pyc} ${_bin_pyo} DESTINATION ${DESTINATION_DIR}/__pycache__/)
     ELSE (PYTHON_SHORT_VERSION GREATER 3.1)
-        INSTALL(FILES ${_bin_pyc} DESTINATION ${DESTINATION_DIR})
+        INSTALL(FILES ${_bin_pyc} ${_bin_pyo} DESTINATION ${DESTINATION_DIR})
     ENDIF (PYTHON_SHORT_VERSION GREATER 3.1)
   ENDIF("$ENV{PYTHONDONTWRITEBYTECODE}" STREQUAL "")
 
