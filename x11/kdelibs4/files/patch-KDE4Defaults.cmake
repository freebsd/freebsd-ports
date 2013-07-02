--- ./cmake/modules/KDE4Defaults.cmake.orig	2012-11-01 23:08:00.000000000 +0000
+++ ./cmake/modules/KDE4Defaults.cmake	2012-11-02 15:05:55.862878877 +0000
@@ -21,12 +21,12 @@
 # define the generic version of the libraries here
 # this makes it easy to advance it when the next KDE release comes
 # Use this version number for libraries which are at version n in KDE version n
-set(GENERIC_LIB_VERSION "4.10.4")
-set(GENERIC_LIB_SOVERSION "4")
+set(GENERIC_LIB_VERSION "5.0.1")
+set(GENERIC_LIB_SOVERSION "5")
 
 # Use this version number for libraries which are already at version n+1 in KDE version n
-set(KDE_NON_GENERIC_LIB_VERSION "5.10.4")
-set(KDE_NON_GENERIC_LIB_SOVERSION "5")
+set(KDE_NON_GENERIC_LIB_VERSION "7.0.1")
+set(KDE_NON_GENERIC_LIB_SOVERSION "7")
 
 # windows does not support LD_LIBRARY_PATH or similar
 # all searchable directories has to be defined by the PATH environment var
