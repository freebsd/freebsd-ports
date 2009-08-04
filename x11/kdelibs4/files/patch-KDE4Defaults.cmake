--- ../cmake/modules/KDE4Defaults.cmake.orgi	2009-05-10 10:28:06.000000000 +0200
+++ ../cmake/modules/KDE4Defaults.cmake	2009-05-10 10:29:00.000000000 +0200
@@ -24,12 +24,12 @@
 # define the generic version of the libraries here
 # this makes it easy to advance it when the next KDE release comes
 # Use this version number for libraries which are at version n in KDE version n
-set(GENERIC_LIB_VERSION "4.3.0")
-set(GENERIC_LIB_SOVERSION "4")
+set(GENERIC_LIB_VERSION "5.0.1")
+set(GENERIC_LIB_SOVERSION "5")
 
 # Use this version number for libraries which are already at version n+1 in KDE version n
-set(KDE_NON_GENERIC_LIB_VERSION "5.3.0")
-set(KDE_NON_GENERIC_LIB_SOVERSION "5")
+set(KDE_NON_GENERIC_LIB_VERSION "7.0.1")
+set(KDE_NON_GENERIC_LIB_SOVERSION "7")
 
 # windows does not support LD_LIBRARY_PATH or similar
 # all searchable directories has to be defined by the PATH environment var
