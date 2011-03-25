--- ./cmake/modules/PythonMacros.cmake.orig	2011-03-10 07:44:37.000000000 -0500
+++ ./cmake/modules/PythonMacros.cmake	2011-03-10 07:46:14.000000000 -0500
@@ -35,6 +35,7 @@
 
   SET(_bin_py ${CMAKE_CURRENT_BINARY_DIR}/${_basepath}/${_filename})
   SET(_bin_pyc ${CMAKE_CURRENT_BINARY_DIR}/${_basepath}/${_filenamebase}.pyc)
+  SET(_bin_pyo ${CMAKE_CURRENT_BINARY_DIR}/${_basepath}/${_filenamebase}.pyo)
 
   FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${_basepath})
 
@@ -46,6 +47,7 @@
       TARGET compile_python_files
       COMMAND ${CMAKE_COMMAND} -E echo ${message}
       COMMAND ${PYTHON_EXECUTABLE} ${_python_compile_py} ${_bin_py}
+      COMMAND ${PYTHON_EXECUTABLE} -O ${_python_compile_py} ${_bin_py}
       DEPENDS ${_absfilename}
     )
   ELSE(_abs_bin_py STREQUAL ${_absfilename})
@@ -54,9 +56,10 @@
       COMMAND ${CMAKE_COMMAND} -E echo ${message} 
       COMMAND ${CMAKE_COMMAND} -E copy ${_absfilename} ${_bin_py}
       COMMAND ${PYTHON_EXECUTABLE} ${_python_compile_py} ${_bin_py}
+      COMMAND ${PYTHON_EXECUTABLE} -O ${_python_compile_py} ${_bin_py}
       DEPENDS ${_absfilename}
     )
   ENDIF(_abs_bin_py STREQUAL ${_absfilename})
 
-  INSTALL(FILES ${_bin_pyc} DESTINATION ${DESINATION_DIR})
+  INSTALL(FILES ${_bin_pyc} ${_bin_pyo} DESTINATION ${DESINATION_DIR})
 ENDMACRO(PYTHON_INSTALL)
