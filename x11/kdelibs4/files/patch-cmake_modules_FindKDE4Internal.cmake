--- cmake/modules/FindKDE4Internal.cmake.orig	2013-05-28 21:33:13.000000000 +0300
+++ cmake/modules/FindKDE4Internal.cmake	2013-06-23 15:03:18.000000000 +0300
@@ -893,8 +893,8 @@
    _set_fancy(XDG_MIME_INSTALL_DIR     "${SHARE_INSTALL_PREFIX}/mime/packages"  "The install dir for the xdg mimetypes")
 
    _set_fancy(SYSCONF_INSTALL_DIR      "${CMAKE_INSTALL_PREFIX}/etc"            "The sysconfig install dir (default ${CMAKE_INSTALL_PREFIX}/etc)")
-   _set_fancy(MAN_INSTALL_DIR          "${SHARE_INSTALL_PREFIX}/man"            "The man install dir (default ${SHARE_INSTALL_PREFIX}/man/)")
-   _set_fancy(INFO_INSTALL_DIR         "${SHARE_INSTALL_PREFIX}/info"           "The info install dir (default ${SHARE_INSTALL_PREFIX}/info)")
+   _set_fancy(MAN_INSTALL_DIR          "${CMAKE_INSTALL_PREFIX}/man"            "The man install dir (default ${CMAKE_INSTALL_PREFIX}/man/)")
+   _set_fancy(INFO_INSTALL_DIR         "${CMAKE_INSTALL_PREFIX}/info"           "The info install dir (default ${CMAKE_INSTALL_PREFIX}/info)")
    _set_fancy(DBUS_INTERFACES_INSTALL_DIR      "${SHARE_INSTALL_PREFIX}/dbus-1/interfaces" "The dbus interfaces install dir (default  ${SHARE_INSTALL_PREFIX}/dbus-1/interfaces)")
    _set_fancy(DBUS_SERVICES_INSTALL_DIR      "${SHARE_INSTALL_PREFIX}/dbus-1/services"     "The dbus services install dir (default  ${SHARE_INSTALL_PREFIX}/dbus-1/services)")
    _set_fancy(DBUS_SYSTEM_SERVICES_INSTALL_DIR      "${SHARE_INSTALL_PREFIX}/dbus-1/system-services"     "The dbus system services install dir (default  ${SHARE_INSTALL_PREFIX}/dbus-1/system-services)")
@@ -1304,6 +1304,50 @@
 endif (CMAKE_COMPILER_IS_GNUCXX)
 
 
+if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
+   set (KDE4_ENABLE_EXCEPTIONS "-fexceptions -UQT_NO_EXCEPTIONS")
+   # Select flags.
+   set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g -DNDEBUG -DQT_NO_DEBUG")
+   set(CMAKE_CXX_FLAGS_RELEASE        "-O2 -DNDEBUG -DQT_NO_DEBUG")
+   set(CMAKE_CXX_FLAGS_DEBUG          "-g -O2 -fno-inline")
+   set(CMAKE_CXX_FLAGS_DEBUGFULL      "-g3 -fno-inline")
+   set(CMAKE_CXX_FLAGS_PROFILE        "-g3 -fno-inline -ftest-coverage -fprofile-arcs")
+   set(CMAKE_C_FLAGS_RELWITHDEBINFO   "-O2 -g -DNDEBUG -DQT_NO_DEBUG")
+   set(CMAKE_C_FLAGS_RELEASE          "-O2 -DNDEBUG -DQT_NO_DEBUG")
+   set(CMAKE_C_FLAGS_DEBUG            "-g -O2 -fno-inline")
+   set(CMAKE_C_FLAGS_DEBUGFULL        "-g3 -fno-inline")
+   set(CMAKE_C_FLAGS_PROFILE          "-g3 -fno-inline -ftest-coverage -fprofile-arcs")
+
+   set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -Wno-long-long -std=iso9899:1990 -Wundef -Wcast-align -Werror-implicit-function-declaration -Wchar-subscripts -Wall -W -Wpointer-arith -Wwrite-strings -Wformat-security -Wmissing-format-attribute -fno-common")
+   # As of Qt 4.6.x we need to override the new exception macros if we want compile with -fno-exceptions
+   # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wnon-virtual-dtor -Wno-long-long -Wundef -Wcast-align -Wchar-subscripts -Wall -W -Wpointer-arith -Wformat-security -Woverloaded-virtual -fno-exceptions -DQT_NO_EXCEPTIONS -fno-common -fvisibility=hidden -Werror=return-type -fvisibility-inlines-hidden")
+   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wnon-virtual-dtor -Wno-long-long -Wundef -Wcast-align -Wchar-subscripts -Wall -W -Wpointer-arith -Wformat-security -Woverloaded-virtual -fno-common -fvisibility=hidden -Werror=return-type -fvisibility-inlines-hidden -Wno-return-type-c-linkage")
+   set(KDE4_C_FLAGS "-fvisibility=hidden")
+
+   set(KDE4_CXX_FPIE_FLAGS "-fPIE")
+   set(KDE4_PIE_LDFLAGS "-pie")
+
+   if (CMAKE_SYSTEM_NAME STREQUAL GNU)
+      set (CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pthread")
+      set (CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -pthread")
+   endif (CMAKE_SYSTEM_NAME STREQUAL GNU)
+
+   set(__KDE_HAVE_GCC_VISIBILITY TRUE)
+
+   # check that Qt defines Q_DECL_EXPORT as __attribute__ ((visibility("default")))
+   # if it doesn't and KDE compiles with hidden default visibiltiy plugins will break
+   set(_source "#include <QtCore/QtGlobal>\n int main()\n {\n #ifndef QT_VISIBILITY_AVAILABLE \n #error QT_VISIBILITY_AVAILABLE is not available\n #endif \n }\n")
+   set(_source_file ${CMAKE_BINARY_DIR}/CMakeTmp/check_qt_visibility.cpp)
+   file(WRITE "${_source_file}" "${_source}")
+   set(_include_dirs "-DINCLUDE_DIRECTORIES:STRING=${QT_INCLUDES}")
+   try_compile(_compile_result ${CMAKE_BINARY_DIR} ${_source_file} CMAKE_FLAGS "${_include_dirs}" OUTPUT_VARIABLE _compile_output_var)
+   if(NOT _compile_result)
+       message("${_compile_output_var}")
+       message(FATAL_ERROR "Qt compiled without support for -fvisibility=hidden. This will break plugins and linking of some applications. Please fix your Qt installation (try passing --reduce-exports to configure).")
+   endif(NOT _compile_result)
+endif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
+
+
 if (CMAKE_C_COMPILER MATCHES "icc")
 
    set (KDE4_ENABLE_EXCEPTIONS -fexceptions)
