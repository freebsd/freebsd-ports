--- cmake/modules/FindKDE4Internal.cmake.orig	2010-06-02 02:55:14.000000000 -0400
+++ cmake/modules/FindKDE4Internal.cmake	2010-06-02 02:57:53.000000000 -0400
@@ -689,7 +689,7 @@
 # whether to install a CMake FooConfig.cmake into lib/foo/cmake/ or /lib/cmake/foo/
 # (with 2.6.3 and above also lib/cmake/foo/ is supported):
 if(${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION} VERSION_GREATER 2.6.2)
-   option(KDE4_USE_COMMON_CMAKE_PACKAGE_CONFIG_DIR "Prefer to install the <package>Config.cmake files to lib/cmake/<package> instead to lib/<package>/cmake" TRUE)
+   option(KDE4_USE_COMMON_CMAKE_PACKAGE_CONFIG_DIR "Prefer to install the <package>Config.cmake files to lib/cmake/<package> instead to lib/<package>/cmake" FALSE)
 else(${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION} VERSION_GREATER 2.6.2)
    set(KDE4_USE_COMMON_CMAKE_PACKAGE_CONFIG_DIR  FALSE)
 endif(${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION} VERSION_GREATER 2.6.2)
@@ -855,8 +855,8 @@
    _set_fancy(XDG_MIME_INSTALL_DIR     "${SHARE_INSTALL_PREFIX}/mime/packages"  "The install dir for the xdg mimetypes")
 
    _set_fancy(SYSCONF_INSTALL_DIR      "${CMAKE_INSTALL_PREFIX}/etc"            "The sysconfig install dir (default ${CMAKE_INSTALL_PREFIX}/etc)")
-   _set_fancy(MAN_INSTALL_DIR          "${SHARE_INSTALL_PREFIX}/man"            "The man install dir (default ${SHARE_INSTALL_PREFIX}/man/)")
-   _set_fancy(INFO_INSTALL_DIR         "${SHARE_INSTALL_PREFIX}/info"           "The info install dir (default ${SHARE_INSTALL_PREFIX}/info)")
+   _set_fancy(MAN_INSTALL_DIR          "${CMAKE_INSTALL_PREFIX}/man"            "The man install dir (default ${SHARE_INSTALL_PREFIX}/man/)")
+   _set_fancy(INFO_INSTALL_DIR         "${CMAKE_INSTALL_PREFIX}/info"           "The info install dir (default ${SHARE_INSTALL_PREFIX}/info)")
    _set_fancy(DBUS_INTERFACES_INSTALL_DIR      "${SHARE_INSTALL_PREFIX}/dbus-1/interfaces" "The dbus interfaces install dir (default  ${SHARE_INSTALL_PREFIX}/dbus-1/interfaces)")
    _set_fancy(DBUS_SERVICES_INSTALL_DIR      "${SHARE_INSTALL_PREFIX}/dbus-1/services"     "The dbus services install dir (default  ${SHARE_INSTALL_PREFIX}/dbus-1/services)")
    _set_fancy(DBUS_SYSTEM_SERVICES_INSTALL_DIR      "${SHARE_INSTALL_PREFIX}/dbus-1/system-services"     "The dbus system services install dir (default  ${SHARE_INSTALL_PREFIX}/dbus-1/system-services)")
